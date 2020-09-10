def insertionsort(array: Array[Double]) = {

  //for every item in the array except at index 0  
  for (j <- 1 until array.length) {

    //key is the element at current index j  
    var key = array(j)

    //i is the index right before j
    var i = j - 1

    //loop over all elements before key
    //loop works if index before j is within bounds
    //and element directly before key is larger than key
    while(i > -1 && array(i) > key) {
    
      //if we are this far, element right before key is larger than key
      //we make element at i + 1 equal to element right before it
      array(i + 1) = array(i)
      //and then move left
      i -= 1
    }
    //finally, when the while loop is over
    // we are left everything up to index j sorted
    //and duplicate elements at positions i and i + 1
    //we place key at position i + 1, in the place of one of duplicates
    array(i + 1) = key
  }
}