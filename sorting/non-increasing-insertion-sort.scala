def reverse_insertion_sort(array: Array[Double]) = {

  for (j <- array.length - 2 to 0 by -1 ) {

    var key = array(j)

    var i = j + 1

    while(i < array.length && array(i) > key) {
    
      array(i - 1) = array(i)

      i += 1
    }

    array(i - 1) = key
  }
}