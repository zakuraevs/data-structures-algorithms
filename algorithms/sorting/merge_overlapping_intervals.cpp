// Given a vector of intervals [start, end], merge all overlapping intervals
// in no particular order.
// O(n logn) time, O(n) space

#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
	
	vector<vector<int>> result;
	size_t n = intervals.size();
	
	if (n < 2)
		return intervals;
	
	// sort input intervals by first elements
	sort(intervals.begin(), intervals.end());
	
	vector<int> current_interval = intervals[0];
	vector<int> next_interval = intervals[1];
	
	// iterate over all sorted intervals:
	for (int i = 1; i < n; ++i) {
		next_interval = intervals[i];
		int current_start = current_interval[0];
		int current_end = current_interval[1];
		int next_start = next_interval[0];
		int next_end = next_interval[1];
		
		if (current_end > next_end) {
			// disregard next
			continue;
		} else if (next_start <= current_end) {
			// merge the two intervals
			current_interval = {current_start, next_end};
		} else {
			// add current to result
			result.push_back(current_interval);
			current_interval = next_interval;
		}
	}
	result.push_back(current_interval);
  
  return result;
}
