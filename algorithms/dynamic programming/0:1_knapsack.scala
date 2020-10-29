case class Item(val weight: Int, val value: Int) {
}

def solveDynProg(maxWeight: Int, items: Seq[Item]): (Int, Seq[Item]) = {

    // Check that all weights and values are positive
    items.foreach({case Item(weight, value) => {
      require(weight > 0)
      require(value > 0)
    }})

    val m = items.size
    val table = Array.fill(maxWeight+1)(Array.fill(m)(0))
    var optimal_value: Int = -1
    var optimal_items = Seq[Item]()

    // loop of base case, the first item
    for(weight <- 0 to maxWeight) {
      val first_item_weight = items(0).weight
      val first_item_value = items(0).value

      if(weight >= first_item_weight) table(weight)(0) = first_item_value
      else table(weight)(0) = 0
    }

    // loop over all other items
    for(item_index <- 1 until m) {
      val current_item_weight = items(item_index).weight
      val current_item_value = items(item_index).value

      for(weight <- 0 to maxWeight) {
        val value_with_current_item = {
          if(current_item_weight <= weight) {

            // not sure about this one below
            val best_value_before_current_item = table(weight - current_item_weight)(item_index-1)

            // this is the value with current item
            best_value_before_current_item + current_item_value
          } else 0
        }

        val value_without_current_item = table(weight)(item_index-1)

        table(weight)(item_index) = scala.math.max(value_with_current_item, value_without_current_item)
      }
    }

    optimal_value = table(maxWeight)(m-1)

    // now we need to find what are the items that we took:

    var temp_value = optimal_value
    var current_row = maxWeight
    var current_column = m-1

    while(temp_value > 0 && current_column >= 0 && current_row >= 0) {
      var we_picked_current_item: Boolean = {

        if(items(current_column).weight <= current_row) {
          if(current_column > 0) {
            table(current_row)(current_column) - items(current_column).value == table(current_row-items(current_column).weight)(current_column-1)
          } else {
            table(current_row)(current_column) != table (current_row-1)(current_column)
          }
        } else false

      }
      if(we_picked_current_item) {
        optimal_items = optimal_items :+ items(current_column)
        temp_value = temp_value - items(current_column).value
        current_row = current_row - items(current_column).weight
        current_column = current_column - 1
      } else {
        if(current_column == 0 && table(current_row)(current_column) > 0 ) {
          optimal_items = optimal_items :+ items(current_column)
        }
        current_column = current_column - 1
      }
    }

    (optimal_value, optimal_items)

  }