// Given an array of positive integers,
// Find the maximum possible sum of non-adjacent elements
// O(n) time and space

#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
	int n = array.size();
	if(!n) return 0;
	
	// We are going to keep track of solutions to subproblems
	vector<int> maxes(n+1, 0);
	maxes[1] = array[0];
	
	for(int i=1; i<n; i++) {
		maxes[i+1] = max(maxes[i-1] + array[i], maxes[i]);
	}
		
  return maxes[n];
}
