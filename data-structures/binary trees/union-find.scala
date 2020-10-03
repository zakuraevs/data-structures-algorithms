// this class keeps track of a window of values
// upon inserting a new value, the window is updated, 
// and the smallest and largest elements in the window are returned

class MovingWindow[A <% Ordered[A]](windowSize: Int) {
  val q = new scala.collection.mutable.Queue[A]()
  val m = new java.util.TreeMap[A, Int]()

  def insert(value: A): (A, A) = {


    if(q.size == windowSize) {
      var elem = q.dequeue
      var count = m.get(elem)
      if(count == 1){
        m.remove(elem)
      } else {
        m.put(elem, count - 1)
      }
    }
    q.enqueue(value)

    var current = m.get(value)
    if(current == 0) {
      m.put(value, 1)
    } else {
      m.put(value, current + 1)
    }

    (m.firstKey(), m.lastKey())
  }
}