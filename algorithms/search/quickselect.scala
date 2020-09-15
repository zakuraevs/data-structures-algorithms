
  def swap(a: Array[Int], i: Int, j: Int): Unit = {
    val t = a(i)
    a(i) = a(j)
    a(j) = t
  }

  def three_way_partition(a: Array[Int], low: Int, high: Int): (Int, Int) = {
    val rand = new scala.util.Random()
    var less_than_pivot = low
    var greater_than_pivot = high
    var pivotIndex = low + rand.nextInt(high - low)
    var i = low
    if(a(low+1) == a(high) ) pivotIndex = high
    val pivot = a(pivotIndex)
    swap(a, pivotIndex, high)
    
    while(i <= greater_than_pivot) {
      if(a(i) < pivot) {
        swap(a, i, less_than_pivot)
        i += 1
        less_than_pivot += 1
      } else if(a(i) > pivot) {
        swap(a, i, greater_than_pivot)
        greater_than_pivot -= 1
      } else {
        i += 1
      }
    }
    return (less_than_pivot, greater_than_pivot)
  }

  def quickselect(a: Array[Int], low: Int, high: Int, k: Int ): Int = {
    if (low == high) return a(low)

    val pivotIndex = three_way_partition(a, low, high)

    if (k == pivotIndex._1 || k == pivotIndex._2) return a(k)
    else if (k < pivotIndex._1) return quickselect(a, low, pivotIndex._1 - 1, k)
    else return quickselect(a, pivotIndex._2 , high, k)
  }
