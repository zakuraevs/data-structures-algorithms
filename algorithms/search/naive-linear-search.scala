def find(array: Array[Double], value: Double): Int = {

  for(i <- 0 until array.length) {
    if(array(i) == value) return i
  }

  return -1
}

/*
loop invariant (stays true regardless of iteration):

at the start of each iteration of the for loop of lines 3-5,
the subarray array(1...i-1) does not contain the target value.

Need to show 3 things about the invariant to show that the
algorithm is correct

Initialization: invariant is true prior to the first iteration
- yes, empty array does not contain target value

Maintenance: if the invariant is true before an iteration
of the loop, it remains true before the next iteration
- yes, if the value is found during the iteration, the function stops
  if not, then another element is added to checked subarray

Termination: when the loop terminates, the invariant gives us a
useful property that helps show that the algorithm is correct
- if the array length is n, then n+1 checks were performed at the start of 
  iterations. If this is true, that we are left with an array of length n
  which does not contain the target value 
*/