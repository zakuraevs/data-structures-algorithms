// Given a matrix of 1s and 0s, replace all 1's that are
// not "connected" to the border of the matrix (horiz or vert thru other 1s) with 0s
// O(wh) time and space, w = width, h = height. 

#include <vector>
#include <queue>
using namespace std;


vector<pair<int, int>> get_neighbors(vector<vector<bool>>& border_ones, const vector<vector<int>>& matrix, int row, int col) {
	
	vector<pair<int, int>> neighbors;
	
	size_t height = matrix.size();
	size_t width = matrix[0].size();
	
	// in bounds, haven't visited yet and a one
	if (row > 0 && !border_ones[row-1][col] && matrix[row-1][col] == 1)
		neighbors.push_back(make_pair(row-1,col));
	if (row < height - 1 && !border_ones[row+1][col] && matrix[row+1][col] == 1)
		neighbors.push_back(make_pair(row+1,col));
	if (col > 0 && !border_ones[row][col-1] && matrix[row][col-1] == 1)
		neighbors.push_back(make_pair(row,col-1));
	if (col < width - 1 && !border_ones[row][col+1] && matrix[row][col+1] == 1)
		neighbors.push_back(make_pair(row,col+1));
	
	return neighbors;
}

void bfs_mark(vector<vector<bool>>& border_ones, const vector<vector<int>>& matrix, int row, int col) {
	
	queue<pair<int, int>> unvisited;
	unvisited.push(make_pair(row, col));
	
	while (!unvisited.empty()) {
		
		pair<int, int> current_coords = unvisited.front();
		unvisited.pop();
			
		int row_current = current_coords.first;
		int col_current = current_coords.second;
		
		border_ones[row_current][col_current] = true;
		
		vector<pair<int, int>> current_neighbors = get_neighbors(border_ones, matrix, row_current, col_current);
		
		for (pair<int, int> neighbor : current_neighbors) {
			unvisited.push(neighbor);
		}

	}
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  
	size_t height = matrix.size();
	if (height == 0) return matrix;
	size_t width = matrix[0].size();
	
	// We mark all 1's that are connected to the border as true
	vector<vector<bool>> border_ones = vector<vector<bool>>(height, vector<bool>(width, false));
	
	// Checking row 0:
	for (int col = 0; col < width; col++) {
		if (border_ones[0][col])
			continue;
		if (matrix[0][col] == 1)
			bfs_mark(border_ones, matrix, 0, col);
	}
	
	// Checking row height - 1:
	int last_row = height - 1;
	for (int col = 0; col < width; col++) {
		if (border_ones[last_row][col])
			continue;
		if (matrix[last_row][col] == 1)
			bfs_mark(border_ones, matrix, last_row, col);
	}
	
	// Checking col 0:
	for (int row = 0; row < height; row++) {
		if (border_ones[row][0])
			continue;
		if (matrix[row][0] == 1)
			bfs_mark(border_ones, matrix, row, 0);
	}
	
	// Checking col width - 1:
	int last_col = width - 1;
	for (int row = 0; row < height; row++) {
		if (border_ones[row][last_col])
			continue;
		if (matrix[row][last_col] == 1)
			bfs_mark(border_ones, matrix, row, last_col);
	}
	
	for (int row = 1; row < last_row; row++) {
		for (int col = 1; col < last_col; col++) {
			if (!border_ones[row][col])
				matrix[row][col] = 0;
		}
	}
	
  return matrix;
}
