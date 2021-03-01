// Given a vector of integers,
// return the powersest (in vector form) of it
// O(n*n^2) time and space.

#include <vector>
using namespace std;

// O(n * 2^n) time and space
vector<vector<int>> powerset(vector<int> array) {
  
	vector<vector<int>> powerset = {{}};
	
	for (int& current : array) {
		size_t n = powerset.size();
		for (int i = 0; i < n; i++) {
			vector<int> new_subset = powerset[i];
			new_subset.push_back(current);
			powerset.push_back(new_subset);
		}
	}
	
  return powerset;
}


