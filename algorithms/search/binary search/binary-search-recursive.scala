
// T <% Ordered[T] means that type T must be convertible to type Ordered[T]
def binarySearchRecursive[T <% Ordered[T]](arr: Array[T], e: T): Boolean = {
  def inner(left: Int, right: Int): Boolean = {
    if(left <= right) {
      val mid = left + ((hi - right) / 2) // (lo + hi) / 2 causes an overflow at suficiently large values
      val cmp = e compare arr(mid)
      if(cmp == 0) true                 // e == arr(mid)
      else if(cmp < 0) inner(left, mid-1) // e < arr(mid)
      else inner(mid+1, right)             // e > arr(mid)
    } else
      false
  }
  inner(0, arr.length-1)
}