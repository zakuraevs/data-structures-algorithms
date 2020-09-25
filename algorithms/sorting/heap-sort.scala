def heapsortInt(a: Array[Int]) {
  /*
   * The parent index of the node at index i.
   * Should not be called for the root node 0.
   */
  def parent(i: Int): Int = (i-1) / 2
  // The left child index of the node at the index i.
  def leftChild(i: Int): Int = 2*i+1
  // The right child index of the node at the index i.
  def rightChild(i: Int): Int = 2*i+2
  
  // Swap the lements at indices i and j.
  def swap(i: Int, j: Int) { val t = a(i); a(i) = a(j); a(j) = t }
  
  // Push the node at index "start" downwards
  // in the heap represented by the sub-array a[0..end].
  def downHeap(start: Int, end: Int) {
    var node = start
    while(leftChild(node) <= end) {
      var child = leftChild(node)
      var dest = node
      if(a(dest) < a(child))
        dest = child
      if(child+1 <= end && a(dest) < a(child+1))
        dest = child + 1
      if(dest == node) return
      swap(node, dest)
      node = dest 
    }
  }

  val n = a.length
  if(n <= 1) return
  
  // Build the initial heap
  var index = parent(n-1)
  while(index >= 0)  {
    downHeap(index, n-1)
    index -= 1
  }

  // Move the current largest element to the correct position
  // in the final result, apply downheap to the new root element.
  var end = n - 1
  while(end > 0) {
    // a(0) is the heap root, ie. the largest element in the current heap.
    // Move it to the correct position a(end) in the final result.
    swap(0, end)
    // Decrease the heap size by one
    end -= 1
    // Push the new root element down the heap
    downHeap(0, end)
  }
}