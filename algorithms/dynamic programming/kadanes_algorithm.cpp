// Givan an array of integers, find the sum
// of the max contiguesour subarray
// O(n) time, constant space

#include <vector>
#include <limits>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
	
	int maximum = INT_MIN;
	int current = 0;
	int n = array.size();
	
	for (int i = 0; i < n; i++) {
		
		int value = array[i];
		int current_sum = current + value;
		current = max(current_sum, value);
		maximum = max(maximum, current);
		
	}
	
  return maximum;
}