// Given an array of integers,
// Check whether it is monotonic
// O(n) time, constant space

bool isMonotonic(vector<int> array) {
	
	int n = array.size();
	if( n < 2) return true;
	
	bool non_increasing = true;
	bool non_decreasing = true;
	
	for(int i = 1; i < n; i++) {
		
		if(array[i] < array[i - 1]) {
			non_decreasing = false;
		}
		if(array[i] > array[i - 1]) {
			non_increasing = false;
		}
	}
	
  return non_increasing || non_decreasing;
}
