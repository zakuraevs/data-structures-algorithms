
// WIP
// These methods calculate the eccentricity and diameter of a graph given by 

  def eccentricity(v: Int, nofVertices: Int): Int = {
    val visited_nodes = ArrayBuffer.fill(nofVertices){-1}
    visited_nodes(v) = (0)

    val q = mutable.Queue[Int](v)
    while(q.nonEmpty) {
      val current_node = q.dequeue()
      val neighboring_nodes = neighbours(current_node)
      for(node <- neighboring_nodes){
        if( visited_nodes(node) == -1 ) {
          visited_nodes(node) = visited_nodes(current_node) + 1
          q.enqueue(node)
        }
      }
    }

    visited_nodes.max
  }

  
  def diameter: Int = {
    Range(0, nofVertices-1).map(eccentricity).max
  }
