def lsdfRadixSort(a: Array[Int]): Unit = {
    val n = a.length
    if(n <= 1) return

    val bits_per_integer = 32 // each int is 32 bits
    val bytes_per_integer = bits_per_integer / 8 // each int is 4 bytes: 32/8 = 4
    val byte_range = 1 << 8 // = 256. Each bytes is between 0 and 255. Practically takes 1 and left shifts it by 8: multiplying 1 with 2^8 = 100000000
    val mask = byte_range - 1 // 0xff

      val auxiliary = new Array[Int](n)

      // main loop for 0 until 4
      var d = 0
      while(d < bytes_per_integer) {

        // empty array of length 257, 1 more than byte range: will contain counts of each byte.
        val count = new Array[Int](byte_range + 1)
        //println("count: ", count)

        // for each integer in original array a
        var i = 0
        while(i < n) {
          // gets the dth byte of the integer starting from the right. Good explanation here: https://stackoverflow.com/questions/10493411/what-is-bit-masking
          val c = (a(i) >> 8 * d) & mask
          // increments the count of retrieved byte. the 0th position is untouched. Form of (0, 0, 0, 1, 0, 2, 0, ..., 0)
          count(c + 1) += 1
          i += 1
        }

        // for each of the 256 values in a byte
        var r = 0
        while(r < byte_range) {
          // value in count(r+1) is equal to the previous values. This fills 0 elements of count and turns non-0 into cumulates
          count(r + 1) += count(r) // form of (0, 0, 0, 1, 1, 3, 3, ..., 24) numbers are arbitrary
          r += 1
        }

        // dealing with negatives
        // if d is 3, the most significant byte, where the signature bit is stored
        if (d == bytes_per_integer - 1) {

          //shift 1 is equivalent to the total number in range from -128 to 255
          val shift1 = count(byte_range) - count(byte_range / 2)
          // number at 127
          val shift2 = count(byte_range / 2)

          for (r <- 0 until byte_range / 2) {
            count(r) += shift1
          }
          for (r <- byte_range / 2 until byte_range) {
            count(r) -= shift2
          }
        }

        // move from a to auxiliary into correct indices
        i = 0
        while(i < n) {

          // c is the dth byte of each integer
          val c = (a(i) >> 8 * d) & mask
          // the element in auxiliary at position count(c) is equal to a(i).
          auxiliary(count(c)) = a(i)
          count(c) += 1
          i += 1
        }

        // move back into a
        i = 0
        while(i < n) {
          a(i) = auxiliary(i)
          i += 1
        }

        d += 1

    }
  }