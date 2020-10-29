/**
* Given an array of integers, this algorithm finds the first index, 
* last index and the sum of elements of the largest contigious subarray in linear time.
*/

def max_cont_subarray(a: Array[Int]): (Int,Int,Int) = {
    require(a.nonEmpty)

    var current_start = 0
    var best_start = 0
    var current_end = 0
    var best_end = 0
    var current_sum = a(0)
    var best_sum = a(0)
    var n = a.size
    var i = 1

    while(i < n) {
      if(a(i) > current_sum + a(i)){
        current_sum = a(i)
        current_start = i
      } else {
        current_sum += a(i)
      }
      current_end = i

      if(current_sum > best_sum) {
        best_sum = current_sum
        best_start = current_start
        best_end = current_end
      }
      i += 1
    }

    (best_start, best_end, best_sum)

  }