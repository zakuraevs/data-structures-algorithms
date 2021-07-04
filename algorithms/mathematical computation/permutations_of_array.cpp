// Given an array,
// return all permutations of it
// O(n!*n) space and time, where n is the size of the input array.

#include <vector>
using namespace std;

vector<vector<int>> inner(const vector<int>& array, const int& original_size) {
		
	size_t n = array.size();
	if (n == 0) return {};
	if (n == 1) return {array};
	if (n == 2) return {{array[0], array[1]}, {array[1], array[0]}};
	
	vector<vector<int>> permutations;
	
	for (int i = 0; i < n; i++) {
		int head = array[i];
		
		vector<int> tail;
		for (int j = 0; j < n; j++) {
			if (j != i)
				tail.push_back(array[j]);
		}

		vector<vector<int>> permutations_starting_w_head = inner(tail, original_size);
			
		for (vector<int>& p : permutations_starting_w_head) {
			p.insert(p.begin(), head);
		}
		
		for (vector<int> p : permutations_starting_w_head) {
			permutations.push_back(p);
		}	
	}
	
	return permutations;
}

vector<vector<int>> getPermutations(vector<int> array) {
	return inner(array, array.size());
}
