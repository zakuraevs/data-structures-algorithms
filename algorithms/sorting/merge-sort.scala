def merge(a: Array[Int], auxiliary: Array[Int], start: Int, mid: Int, end: Int): Unit = {
  var (i, j, dest) = (start, mid, start)
  // the condition below is && so that i does not go into j's territory
  while(i < mid && j <= end) { // merging two subarrays into auxiliary, starting with smallest. While i,j are within subarrays
    if(a(i) <= a(j)) { // comparing corresponding elemnts of subarrays
      auxiliary(dest) = a(i) // copy smallest
      i += 1
    } else {
      auxiliary(dest) = a(j) // copy smallest
      j += 1
    }
    dest +=1 // increment where we are copying too either way
  }
  // there are probably some elements in one of the subarrays left, which have not been copied to auxiliary yet, 
  // since the above loop condition is &&
  while(i < mid) {
    auxiliary(dest) = a(i)
    i += 1
    dest += 1
  }
  while(j <= end) {
    auxiliary(dest) = a(j)
    j += 1
    dest += 1
  }
  dest = start // copying merged back to main from auxiliary
  while(dest <= end) {
    a(dest) = auxiliary(dest)
    dest += 1
  }
}

def mergesort(a: Array[Int]): Unit = {
  if(a.length <= 1) return

  val auxiliary = new Array[Int](a.length)

  def _mergesort(start: Int, end: Int): Unit = {
    if(start >= end)
      return
    val mid = start + (end - start) / 2 // just like in binary search
    _mergesort(start, mid)
    _mergesort(mid + 1, end)
    merge(a, auxiliary, start, mid + 1, end)
  }
  _mergesort(0, a.length - 1)
}