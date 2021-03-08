// Given a matrix of integers, where each row and each column
// is sorted in ascending order, and a target integer,
// return the indices of the target or {-1, -1}.
// O(m+n) time, constant space. 


#include <vector>
#include <limits>
#include <unordered_set>
using namespace std;


vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {

	size_t rows = matrix.size();
	if (rows == 0)
		return {-1, -1};
	size_t cols = matrix[0].size();
	if (cols == 0)
		return {-1, -1};
	
	int current_row = 0;
	int current_col = cols - 1;
	
	while (current_row <= rows -1 && current_col >= 0) {
		
		int current_value = matrix[current_row][current_col];
		if (current_value == target)
			return {current_row, current_col};
		
		// Eliminate everything in current row (move one row down)
		if (current_value < target)
			current_row++;
		// Eliminate everything in current col (move one col left)
		else 
			current_col--;
	}
	
  return {-1, -1};
}