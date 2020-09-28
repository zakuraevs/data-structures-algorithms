scala.collection.mutable.HashMap

class UnionFind[E] {

  val rank = new HashMap[E, Int]()
  val parents = new HashMap[E, E]()
  var numOfElements = 0
  var numOfSets = 0

  def makeSet(element: E): Boolean = {
    var exists = parents.getOrElse(element, -1)
    if(exists == -1) {
      parents(element) = element
      rank(element) = 0
      this.numOfElements += 1
      this.numOfSets += 1
      return true
    }
    return false
  }
  
  def findSet(element: E): E = {
    var parent = parents(element)
    if(parent == element) element
    else {
      findSet(parent)
    }
  }

  def union(element1: E, element2: E): Unit = {

    var parent1 = parents(element1)
    var parent2 = parents(element2)

    var root1 = findSet(element1)
    var root2 = findSet(element2)

    if(root1 != root2) {
      if(rank(root1) > rank(root2)) {
        parents(root2) = root1
      } else {
        parents(root1) = root2
        if(rank(root1) == rank(root2)) {
          rank(root2) = (rank(root2) + 1)
        }
      }
      this.numOfSets -= 1
     }

  }

  def nofElements: Int = {
    this.numOfElements
  }

  def nofSets: Int = {
    this.numOfSets
  }
}