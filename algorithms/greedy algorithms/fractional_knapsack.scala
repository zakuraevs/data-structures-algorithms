case class Material(val name: String, val amount: Double, valuePerUnit: Double) {
  require(amount >= 0.0)
  require(valuePerUnit > 0.0)
}

def fractional_knapsack(maxAmount: Double, materials: Seq[Material]): (Double, Seq[(Double, Material)]) = {
  require(maxAmount >= 0.0)

  var ratios_and_materials_sorted = materials.toArray.sortBy(m => -(m.valuePerUnit))

  var optimal_value: Double = 0
  var weight: Double = 0.0
  var chosen_materials = new scala.collection.mutable.ArrayBuffer[(Double, Material)]()
  var i = 0

  while(weight < maxAmount) {
    val current_material = ratios_and_materials_sorted(i)˜
    val cma = current_material.amount
    val cmv = current_material.valuePerUnit
    if(cma + weight <= maxAmount) {
      weight += cma
      optimal_value += (cma * cmv)
      val pair = (cma, current_material)
      chosen_materials += pair
    } else {
      val amount_left = maxAmount - weight
      weight = maxAmount
      optimal_value += (amount_left * cmv)
      val pair = (amount_left, current_material)
      chosen_materials += pair
      
    i += 1
  }

  (optimal_value, chosen_materials)
}