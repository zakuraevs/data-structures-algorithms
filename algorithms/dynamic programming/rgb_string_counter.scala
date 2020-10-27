
/*
Suppose an RGB string is a string consisting of characters "r", "g" and "b" such that r cannot be next to g.
There are 3 RGB strings of length 1: "r", "g", "b"
There are 7 RGB strings of length 2: "rr", "rb", "gg", "gb", "bb", "br", "bg"

The algorithm counts the number of RGB strings of length n using dynamic programming.
*/

def count(n: Int): BigInt = {
    require(n > 0)

    var r: BigInt = 1
    var g: BigInt = 1
    var b: BigInt = 1
    var i = 1

    while(i < n) {
      val rtemp = r
      val gtemp = g
      val btemp = b

      r = rtemp + btemp
      g = gtemp + btemp
      b = rtemp + gtemp + btemp

      i += 1
    }
    r + g + b
  }