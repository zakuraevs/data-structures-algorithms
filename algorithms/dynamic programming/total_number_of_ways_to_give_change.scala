// Given an amount n and a set of currentcy denominations, 
// the following algorithms output the total number of ways to combine the denominations to give n

def count_recursive(amount: Int, denominations: Set[Int]): Long = {
    require(amount > 0)
    require(denominations.forall(d => d > 0))

    val denominations_array = denominations.toArray
    val m = denominations.size
    val n = amount

    def inner(n: Int, m: Int): Long = {

      // if n is negataive, we can't return a negative amount
      if (n < 0) return 0
      // there is 1 way to return nothing: not to return anything at all
      if (n == 0) return 1
      // if there are no denominations, there is no way to return anything at all
      if (m <= 0) return 0

      // if we're here, then all of the above conditions are false

      // there are possibly multiple ways to divide n into denominations. We split these solutions in 2 sets:
      // the ones that include a given denomination m and the ones that do not
      // thus we have, in a verbose but more intuitive code:
      val numof_solution_that_includes_mth_denomination: Long = inner(n - denominations_array(m-1),m)
      val numof_solution_that_deos_not_includes_mth_denomination: Long = inner(n,m-1)

      // and we return the total num of solutions from the 2 sets
      numof_solution_that_includes_mth_denomination + numof_solution_that_deos_not_includes_mth_denomination
    }
    inner(amount, m)
  }

  def count_2d_table(amount: Int, denominations: Set[Int]): Long = {
    // NOTE: drawing the 2d table for simple values, eg n=10, denoms=(1,5,10,25) helps a lot
    require(amount > 0)
    require(denominations.forall(d => d > 0))

    // this is the set turned into array, so that we can iteratively access elements by index
    val denominations_array = denominations.toArray
    // for convenience
    val m = denominations.size
    val n = amount

    // 2d table with rows as amounts from 0 to n and coulmns as indices of denominations in denominations_array
    // a table entry table(i)(j) tells how many ways there are to get the amount i using denominations in denominations_array at index j
    val table: Array[Array[Long]] = Array.fill(n + 1)(Array.fill(m)(0))

    // we fill the first row with 1s since this is the base case: there is only one way to choose amount 0 with any denomination
    for(i <- 0 until m)
      table(0)(i) = 1

    // we build all solutions up to n bottom down, starting with amount 1
    // looping over all possible amounts
    for (i <- 1 to n) {
      // looping over indices of all possible denominations
      for(j <- 0 until m) {

        // number of combinations including the current denomination denominations_array(j):
        // if the current amount - current denomination is less than 0, we return 0 (denomination is too big)
        // otherwise we return the value in the table at the amount decreased by current denomination. For example
        // if i = 10 and denominations_array starts as (1,5,...) and denominations_array(j) = 5,
        // we would jump to the table value at amount 5, which is 2 (1+1+1+1+1 and 5)
        val with_denominations_array_m = if(i-denominations_array(j) >= 0) table(i-denominations_array(j))(j) else 0

        // number of combinations excluding the current denomination denominations_array(j):
        // if the current denomination index is 0, then there are no earlier denominations, and so there are no ways
        // to make the amount with no denominations at all
        // otherwise we look at the number of ways to split the current amount but with all known denominations except the current one
        // ie with the previous denomination
        val without_denominations_array_m = if(j >= 1) table(i)(j-1) else 0

        // we set the current entry as the sum of the 2 values calculated above
        table(i)(j) = with_denominations_array_m + without_denominations_array_m
      }
    }

    // we return the farthest value calculated, which is what we need
    table(n)(m-1)
  }

  def count(amount: Int, denominations: Set[Int]): Long = {
    require(amount > 0)
    require(denominations.forall(d => d > 0))

    val denominations_array = denominations.toArray
    val m = denominations.size
    val n = amount

    val table = Array.fill[Long](n + 1)(0)

    table(0) = 1

    // here, we are doing the table from 2d version 1 1column at a time, adding each column onto the previous version,
    // starting from the next denomination
    for (i <- 0 until m) {
      for (j <- denominations_array(i) to n) {
        table(j) += table(j - denominations_array(i))
      }
    }
    table(n)
  }
