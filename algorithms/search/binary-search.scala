

def binarySearch[T <% Ordered[T]](arr: Array[T], e: T): Boolean = {
  def inner(lo: Int, hi: Int): Boolean = {
    if(lo <= hi) {
      val mid = lo + ((hi - lo) / 2)
      val cmp = e compare arr(mid)
      if(cmp == 0) true                 // e == arr(mid)
      else if(cmp < 0) inner(lo, mid-1) // e < arr(mid)
      else inner(mid+1, hi)             // e > arr(mid)
    } else
      false
  }
  inner(0, arr.length-1)
}