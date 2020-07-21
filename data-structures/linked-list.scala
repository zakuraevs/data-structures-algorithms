//Impelementation follows William Fiset's implementtion in Java
//Can be found here: https://github.com/williamfiset/Algorithms
//https://blogs.ashrithgn.com/single-linked-list-implementation-in-scala/

class LinkedList {

  private var size: Int = 0
  private var head: Node[T] = null
  private var tail: Node = null

  sealed class Node[T](var data: T) {


  }

}