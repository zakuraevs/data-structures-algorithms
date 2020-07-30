def binaryAddition (a: Array[Int], b:Array[Int]): Array[Int] = {

  val n = a.length

  val c = Array[Int](0,0,0,0,0,0)

  var carryOver = 0

  for(i <- n-1 to 0 by -1) {
    var total = a(i) + b(i) + c(i)
    c(i) = total % 2
    carryOver =
  }

  return c
}

val testArrA = Array(1,0,1,1,0)
val testArrB = Array(1,1,0,1,1)
val res = binaryAddition(testArrA, testArrB)

for(i <-  res) {
  println(i)
}