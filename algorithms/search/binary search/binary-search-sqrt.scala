// This function checks if a given value x is a square of some integer and if yes, returns that integer

def binarySearchSqrt(x: Int): Int = {
   var candidates = Array[Int]()

   for(i <- 1 to x) {
     candidates = candidates :+ i
   }

   var left = 0
   var right = candidates.length-1


   while(left <= right) {
     val mid = left + (right - left)/2

     if(candidates(mid)*candidates(mid) == x) {
       return candidates(mid)
     } else if (candidates(mid)*candidates(mid) < x) {
       left = mid+1
     } else {
       right = mid-1
     }
   }
   return -1
 }