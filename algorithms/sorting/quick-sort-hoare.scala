// WIP, NOT WORKING
def swap(a: Array[Int], i: Int, j: Int): Unit = {
  val t = a(i)
  a(i) = a(j)
  a(j) = t
}

def partition(a: Array[Int], low: Int, high: Int ): Int = {
  val pivot = a(high) // might not be optimal pivot selection
  var i = low - 1
  var j = low
  while(j <= j) {
    while( i < j && a(i) <= pivot) {
      i = i + 1
    }
    do {
      j = j - 1
    } while (i <= j && a(j) > pivot) 
    if (i < j) {
      swap(a, i, j)
    } 
  }
  swap(a, high, i)
  i
}


def quicksort(a: Array[Int]): Unit = {
  def _quicksort(low: Int, high: Int): Unit = {
    val q = partition(a, low, high)
    if(low < q - 1) _quicksort(low, q - 1)
    if(q + 1 < high) _quicksort(q + 1, high)
  }
  if(a.length >= 2) _quicksort(0, a.length - 1)
}