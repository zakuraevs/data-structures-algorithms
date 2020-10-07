
/**
 * An ordered map class, implemented with AVL trees.
 */
class TreeMap[Key, Value](implicit ord: Ordering[Key]) {

  /** The root node which gets updated */
  var root: Node[Key, Value] = null

  /** Tracks the number of keys */
  private var _nofKeys = 0

  /** The size of the tree */
  def size: Int = _nofKeys

  /** Is the tree empty? */
  def isEmpty = (_nofKeys == 0)


  /** Below are the operations on the tree.
   * These include getting a value by a key, finding the minimum value,
   * finding the ceiling given a key, inserting and removing nodes */


  /** Get the value of the key, or None if the key does not have a value.
  *   Should work in time O(h), where h is the height of the tree. */
  def get(key: Key): Option[Value] = {

    @scala.annotation.tailrec def innerTraverse(a: Node[Key, Value], k: Key): Option[Value] = {
      if (ord.compare(a.key, k) == 0) {
        return Some(a.value)
      } else if (ord.compare(a.key, k) < 0) {
        //a.key < b.key
        if (!a.hasRight) return None
        else innerTraverse(a.right, k)
      } else {
        if (!a.hasLeft)  return None
        else innerTraverse(a.left, k)
      }
    }

    innerTraverse(this.root, key)
  }

  /**
   * Return the smallest key in the treemap, or None if the tree is empty.
   * Should work in time O(h), where h is the height of the tree.
   */
  def min: Option[Key] = {
    if (this.isEmpty) return None

    @scala.annotation.tailrec def inner(n: Node[Key, Value]): Key = {
      if (!n.hasLeft) return n.key
      else inner(n.left)
    }

    Some(inner(this.root))
  }

  /**
   * Return the smallest key in the treemap that is equal to or greater than
   * the argument key (or None if the tree is empty or all its keys are
   * less than the argument key).
   * Should work in time O(h), where h is the height of the tree.
   */
  def ceiling(key: Key): Option[Key] = {
    if (this.isEmpty) return None

    @scala.annotation.tailrec def inner(n: Node[Key, Value], best: Option[Key]): Option[Key] = {
      val comparison = ord.compare(n.key, key)
      if (comparison == 0) return Some(n.key)
      else if (comparison < 0 && n.hasRight) inner(n.right, best)
      else if (comparison < 0 && !n.hasRight) return best
      else if (comparison > 0 && !n.hasLeft) return Some(n.key)
      else if (comparison > 0 && n.hasLeft) inner(n.left, Some(n.key))
      else return None
    }

    inner(this.root, None)
  }


  /**
   * Insert the (key,value) mapping in the tree.
   * If the key already has a value, replace it with the new one.
   * Returns the old value of the key or None if it did not have one.
   * Should work in time O(h), where h is the height of the tree.
   * Remember to update the _nofKeys counter.
   */
  def insert(key: Key, value: Value): Option[Value] = {
    //println("---------------INSERTING-----------------")
    //println("inserting " + key + " -> " + value)

    @scala.annotation.tailrec def traverseInsert(a: Node[Key, Value], b: Node[Key, Value]): Unit = {
      if (ord.compare(a.key, b.key) < 0) {
        //a.key < b.key
        if (!a.hasRight) a.right = b
        else traverseInsert(a.right, b)
      } else {
        if (!a.hasLeft) a.left = b
        else traverseInsert(a.left, b)
      }
    }

    @scala.annotation.tailrec def traverseUpdate(a: Node[Key, Value], b: Node[Key, Value]): Unit = {
      if (ord.compare(a.key, b.key) == 0) {
        a.value = b.value
        return
      } else if (ord.compare(a.key, b.key) < 0) {
        if (!a.hasRight) a.right = b
        else traverseUpdate(a.right, b)
      } else {
        if (!a.hasLeft) a.left = b
        else traverseUpdate(a.left, b)
      }
    }

    var newNode = new Node(key, value)
    var output: Option[Value] = None

    if (this.isEmpty) {
      this.root = newNode
      this._nofKeys += 1
      return None
    }

    this.get(key) match {
      case None => {
        traverseInsert(this.root, newNode)
        this._nofKeys += 1
        output = None
      }
      case Some(oldValue) => {
        traverseUpdate(this.root, newNode)
        output = Some(oldValue)
      }
    }

    this.updateHeights(newNode)
    var funbal = this.firtUnbalancedAncestor(newNode)

    if (funbal != None) {
      val n = funbal.get
      val b = n.balance
      if (b < -1) {
        //println("we are left-heavy")
        if (n.left.balance <= 0) rotateRight(n)
        else rotateLeftRight(n);
      } else {
        //println("we are right-heavy")
        if (n.right.balance >= 0) rotateLeft(n)
        else rotateRightLeft(n)
      }
    }
    this.updateHeights(newNode)
    //println("root after insertion: " + root.key)
    //println("root balance: " + root.balance)
    return output
  }

  /**
   * Remove the key from the treemap.
   * Do nothing if the key is not in the treemap.
   * Return the old value of the key or None if the key was not in the treemap.
   * Should work in time O(h), where h is the height of the tree.
   * Remember to update the _nofKeys counter.
   */
  def remove(key: Key): Option[Value] = {
    //println("--------------REMOVING------------------")
    //println("removing " + key)
    //println("Tree before removal:")
    //println("Root has height: " + root.height)
    //println(this.prettyString)
    if (this.get(key) == None) return None
    var z = this.root

    @scala.annotation.tailrec def largestKeyInSubtree(n: Node[Key, Value]): Node[Key, Value] = {
      if (!n.hasRight) return n
      largestKeyInSubtree(n.right)
    }

    @scala.annotation.tailrec def traverse(n: Node[Key, Value]): Option[Value] = {
      var comparison = ord.compare(n.key, key)
      comparison match {
        case 0 => {
          if (!n.hasRight && !n.hasLeft) {
            z = n.parent
            this.substWith(n, null)
            return Some(n.value)
          } else if (n.hasLeft && !n.hasRight) {
            z = n.parent
            this.substWith(n, n.left)
            return Some(n.value)
          } else if (!n.hasLeft && n.hasRight) {
            z = n.parent
            this.substWith(n, n.right)
            return Some(n.value)
          } else {
            val temp = n.value
            var largestInSubtreeAtN = largestKeyInSubtree(n.left)
            n.key = largestInSubtreeAtN.key
            n.value = largestInSubtreeAtN.value
            z = n
            if (largestInSubtreeAtN.hasLeft) {
              val temp = largestInSubtreeAtN.left
              substWith(largestInSubtreeAtN, temp)
            } else {
              substWith(largestInSubtreeAtN, null)
            }
            return Some(temp)
          }
        }
        case -1 => traverse(n.right)
        case default => traverse(n.left)
      }
    }

    this._nofKeys -= 1
    val res = traverse(this.root)

    // the node has been removed, but the tree could be unbalanced now

    if (this.size == 0 || this.size == 1) return res

    // we update all hights starting from the relevant place
    // println("we start checking starting from " + z.key)
    // println("before performing hight updating, the hight of z is " + z.height)
    this.updateHeights(z)
    // println("before performing any rebalancing, the hight of z is " + z.height)
    // println("and the balance of z is " + z.balance)

    // dealing with z's children
    if (z.hasLeft) {
      val b = z.left.balance
      if (b > 1 || b < -1) {
        if (b < -1) {
          if (z.left.hasLeft && z.left.left.balance <= 0) rotateRight(z.left)
          else rotateLeftRight(z.left);
        } else {
          if (z.left.hasRight && z.left.right.balance >= 0) rotateLeft(z.left)
          else rotateRightLeft(z.left)
        }
      }
      this.updateHeights(z.left)
    }

    var funbal = this.firtUnbalancedAncestor(z)
    while (funbal != None) {
      //println("after deletion, the first unbalanced ancestor we find is " + funbal.get.key)
      val n = funbal.get
      val b = n.balance
      if (b < -1) {
        if (n.left.balance <= 0) rotateRight(n)
        else rotateLeftRight(n);
      } else {
        if (n.right.balance >= 0) rotateLeft(n)
        else rotateRightLeft(n)
      }
      this.updateHeights(z)
      funbal = this.firtUnbalancedAncestor(z)
      //println("after performing rebalancing, the hight of z is " + z.height)
    }
    res
  }

  /** What follows are helper functions for insert and remove operations
   * as well as for checking the tree and visualizing it */

  private def rotateRight(n: Node[Key, Value]) = {
    //println("-------------Right ROTATION-------------------")
    val y = n.left
    val nr = n.right
    val yr = y.right

    this.substWith(n, y)
    y.right = n
    y.right.left = yr
    y.right.right = nr

    var ah = -1
    var bh = -1
    var ch = -1

    if (y.hasLeft) ah = y.left.height
    if (y.right.hasLeft) bh = y.right.left.height
    if (y.right.hasRight) ch = y.right.right.height

    y.right.height = Math.max(bh, ch) + 1
    y.height = y.right.height + 1

    y
  }

  private def rotateLeft(n: Node[Key, Value]) = {
    //println("-------------LEFT ROTATION-------------------")
    val y = n.right
    val nl = n.left
    val yl = y.left

    this.substWith(n, y)
    y.left = n
    y.left.right = yl
    y.left.left = nl

    var ah = -1
    var bh = -1
    var ch = -1

    if (y.hasRight) ah = y.right.height
    if (y.left.hasLeft) ch = y.left.left.height
    if (y.left.hasRight) bh = y.left.right.height

    y.left.height = Math.max(bh, ch) + 1
    y.height = y.left.height + 1

    y
  }

  private def rotateLeftRight(n: Node[Key, Value]) = {
    //println("-------------LEFTRIGHT ROTATION-------------------")
    rotateLeft(n.left)
    rotateRight(n)
  }

  private def rotateRightLeft(n: Node[Key, Value]) = {
    //println("-------------RIGHTLEFT ROTATION-------------------")
    rotateRight(n.right)
    rotateLeft(n)
  }

  @scala.annotation.tailrec private def updateHeights(n: Node[Key, Value]): Unit = {
    if (n != null) {
      if (n.hasLeft) n.left.updateHeight()
      if (n.hasRight) n.right.updateHeight()
      n.updateHeight()
      if (n.hasParent) {
        n.updateHeight()
        updateHeights(n.parent)
      }
    }
  }

  @scala.annotation.tailrec private def firtUnbalancedAncestor(n: Node[Key, Value]): Option[Node[Key, Value]] = {
    if (n.balance < -1 || n.balance > 1) return Some(n)
    else if (n.hasParent) {
      firtUnbalancedAncestor(n.parent)
    } else {
      None
    }
  }

}
