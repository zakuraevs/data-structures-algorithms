def selectionSort(a: Array[Int]): Unit = {
  val n = a.length
  var i = 0

  while(i < n-1) {
    var smallest = a(i)
    var smallest_index = i
    var j = i + 1

    while(j < n) {
      if(a(j) < smallest){
        smallest = a(j)
        smallest_index = j
      }
      j += 1
    }
    a(smallest_index) = a(i)
    a(i) = smallest
    i += 1
  }
}