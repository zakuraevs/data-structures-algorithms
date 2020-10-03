// this class has been written based on material provided by Aalto university course CS-A1140 Data Structures and Algorithms:
// https://plus.cs.aalto.fi/CS-A1140/2020/

class TreeMap[Key, Value](implicit ord: Ordering[Key]) {

  var root: Node[Key, Value] = null

  private var _nofKeys = 0
  def size: Int = _nofKeys
  def isEmpty = (_nofKeys == 0)

  def traverseInsert(a: Node[Key, Value], b: Node[Key, Value]): Unit = {
      if(ord.compare(a.key, b.key) < 0) {
        //a.key < b.key
        if(!a.hasRight) {
          a.right = b
        } else{
          traverseInsert(a.right, b)
        }
      } else {
        if(!a.hasLeft) {
          a.left = b
        } else{
          traverseInsert(a.left, b)
        }
      }
  }

   def traverseUpdate(a: Node[Key, Value], b: Node[Key, Value]): Unit = {
      println("comparing while traverseUpdate. comparisoof keys: " + ord.compare(a.key, b.key))
      if(ord.compare(a.key, b.key) == 0) {
        println("found comparison while travrseUpdate")
        a.value = b.value
        return
      } else if(ord.compare(a.key, b.key) < 0) {
        //a.key < b.key
        if(!a.hasRight) {
          a.right = b
        } else{
          traverseUpdate(a.right, b)
        }
      } else {
        if(!a.hasLeft) {
          a.left = b
        } else{
          traverseUpdate(a.left, b)
        }
      }
   }

  def traverseGet(a: Node[Key, Value], k: Key): Option[Value] = {
      if(ord.compare(a.key, k) == 0) {
        return Some(a.value)
      } else if(ord.compare(a.key, k) < 0) {
        //a.key < b.key
        if(!a.hasRight) {
          return None
        } else{
          traverseGet(a.right, k)
        }
      } else {
        if(!a.hasLeft) {
          return None
        } else{
          traverseGet(a.left, k)
        }
      }
   }

  def insert(key: Key, value: Value): Option[Value] = {
    if (this.isEmpty) {
      this.root = new Node(key, value)
      this._nofKeys += 1
      return None
    }

    val newNode = new Node(key, value)
    this.get(key) match {
      case None => {
        //var current = this.root
        traverseInsert(this.root, newNode)
        this._nofKeys += 1
      }
      case Some(oldValue) => {
        println("found node with same key, updating")
        traverseUpdate(this.root, newNode)
        return Some(oldValue)
      }
    }

    None
  }

  def get(key: Key): Option[Value] = {

    traverseGet(this.root, key)

  }

  def min: Option[Key] = {
    ???
  }

  def ceiling(key: Key): Option[Key] = {
    ???
  }

  def toArray: Array[Key] = {
    val result = new Array[Key](_nofKeys)
    var i = 0
    def inner(node: Node[Key,Value]): Unit = {
      if(node.hasLeft) inner(node.left)
      result(i) = node.key
      i += 1
      if(node.hasRight) inner(node.right)
    }
    inner(root)
    assert(i == _nofKeys)
    result
  }

  private def substWith(n1: Node[Key,Value], n2: Node[Key,Value]): Unit = {
    require(n1 != null)
    // Remove the connection from the previous parent of n2
    if(n2 != null && n2.hasParent) {
      if(n2.parent.left == n2) n2.parent.left = null
      else {assert(n2.parent.right == n2); n2.parent.right = null }
    }
    // Make n2 to substitute n1
    if(n1 == root) {root = n2 }
    else {
      if(n1.parent.left == n1) n1.parent.left = n2
      else {assert(n1.parent.right == n1); n1.parent.right = n2 }
    }
  }

  def remove(key: Key): Option[Value] = {
    ???
  }


  def isValidBST(): Boolean = {
    def inner(n: Node[Key,Value], lower: Option[Key], upper: Option[Key]): Boolean = {
      if(n == null) true
      else if(lower.nonEmpty && ord.compare(n.key, lower.get) <= 0) false
      else if(upper.nonEmpty && ord.compare(n.key, upper.get) >= 0) false
      else inner(n.left, lower, Some(n.key)) && inner(n.right, Some(n.key), upper)
    }
    inner(root, None, None)
  }

  def prettyString: String = prettyString(root)

  def prettyString(subTreeRoot: Node[Key,Value]): String = {
    val s = new scala.collection.mutable.StringBuilder()
    def sep = " "
    def inner(node: Node[Key,Value], indent: String): Unit = {
      s ++= indent
      if(node == null) {
        s ++= "null\n"
      } else {
        s ++= s"key=${node.key} -> value=${node.value}\n"
        inner(node.left, indent+sep)
        inner(node.right, indent+sep)
      }
    }
    inner(subTreeRoot, "")
    s.toString
  }
}
