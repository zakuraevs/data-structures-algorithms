// T <% Ordered[T] means that type T must be convertible to type Ordered[T]
def binarySearchIterative[T <% Ordered[T]](a: Array[T], element: T): Boolean = {

  var left = 0
  var right = a.length-1

  while(left <= right) {
    val mid = left + (right - left)/2

    if(array(mid) == element) {
      return mid
    } else if (array(mid) < element) {
      left = mid+1
    } else {
      right = mid-1
    }
  }

  return -1
}