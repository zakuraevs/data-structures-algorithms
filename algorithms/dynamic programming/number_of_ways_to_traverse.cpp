// Given a n x m grid, if you start
// in top left and need to get to bottom
// right, and can only move down or right,
// in how many ways can you get to the destination?
// O(nm) time and space, suboptimal.

int numberOfWaysToTraverseGraph(int width, int height) {
  // Write your code here.
	std::vector<std::vector<int>> ways(height, std::vector<int>(width, 0));
	
	for (int row = 0; row < height; row++) {
		ways[row][0] = 1;
	}
	for (int col = 0; col < width; col++) {
		ways[0][col] = 1;
	}
	for (int row = 1; row < height; row++) {
		for (int col = 1; col < width; col++) {
			ways[row][col] = ways[row-1][col] + ways[row][col-1];
		}
	}
	
  return ways[height-1][width-1];
}