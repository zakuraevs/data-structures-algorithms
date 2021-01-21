// Given an array of integers,
// find the length of the longest peak.
// A peak is a sequence of integers in the array,
// that are first strictly increasing and then strictly
// decreating.
// O(n) time, O(1) space;

using namespace std;

int longestPeak(vector<int> array) {
  
	// Precompute the size of the input array
	int n = array.size();
	// Track length of longest peak
	int longest = 0;
	// Track length of current peak
	int length = 1;
	// Track whether we increased in current peak
	bool increased = false;
	// Track whether we decreased in current peak
	bool decreased = false;
	// Start at first element
	int i = 1;
	
	// We're looking at all the elements linearly
	while(i < n) {
		
		// We are now going to either traverse a whole peak,
		// Traverse a descent, traverse an ascent, or
		// reach a plateu
		increased = false;
		decreased = false;
		
		// While we're increasing
		while(array[i] > array[i - 1] && i < n) {
			length++;
			i++;
			increased = true;
		}
		
		// We either heat a peak at i-1 or a plateau
		// If we hit a plateau:
		if(array[i] == array[i - 1]) {
			length = 1;
			i++;
			continue;
		}
		
		// If we hit a peak at i - 1:
		// While we're decreasing
		while(array[i] < array[i - 1] && i < n) {
			length++;
			i++;
			decreased = true;
		}
		
		// Now we surely hit a bottom
		// We're now at the element on the plateu or rising.
		// If we both increased and decreased, then we traversed a peak,
		// and we check if it's the longest
		// If we haven't me the conditions, longest will not get
		// the default value 1 of length
		if(length > longest && decreased && increased) {
			longest = length;
		}
			
		// reset lengeth
		length = 1;
	}

	return longest;
}
