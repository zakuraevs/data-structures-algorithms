// Given 2 arrays of integers, find two numbers that 
// are closest to each other
// O(nlogn + mlogm) time and O(1) space

#include <vector>
#include <algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  
	// Sorting both arrays
	std::sort(arrayOne.begin(), arrayOne.end());
	std::sort(arrayTwo.begin(), arrayTwo.end());
	
	// Initialize output
	std::vector<int> res = {arrayOne[0], arrayTwo[0]};
	// Precompute sizes
	int n1 = arrayOne.size();
	int n2 = arrayTwo.size();
	// Initialize pointers
	int i = 0;
	int j = 0;
	
	// Initialize smallest difference
	int best = abs(arrayOne[0] - arrayTwo[0]);
	
	// Iterate over both arrays
	while(i < n1 && j < n2) {
		// Calculate the distance between current numbers
		int distance = abs(arrayOne[i] - arrayTwo[j]);
		
		// Update best and res if needed
		if(distance < best) {
			best = distance;
			res = {arrayOne[i], arrayTwo[j]};
		}

		// Calculate outcomes for possible future moves
		int distance_second = abs(arrayOne[i] - arrayTwo[j+1]);
		int distance_first = abs(arrayOne[i+1] - arrayTwo[j]);
		int distance_both = abs(arrayOne[i+1] - arrayTwo[j+1]);
		
		// Move forward in the best possible direction
		if(distance_second < distance_first && distance_second < distance_both) {
			j++;
		} else if(distance_first < distance_second && distance_first < distance_both) {
			i++;
		} else {
			i++;
			j++;
		}
	}
	
  return res;
}