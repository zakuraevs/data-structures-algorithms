// Given an array of integers in range 1...n,
// and of length n,
// find the earliest integers that repeats,
// i.e. the integer which reapeats and has its
// duplicate at the earliest index

// O(n^2) time, constant space
#include <vector>
#include <unordered_set>

using namespace std;

int firstDuplicateValue(vector<int> array) { 
	
	int n = array.size();
	int best_distance = n;
	int best_second_index = n;
	int best_duplicate = -1;
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(array[i] == array[j] && j < best_second_index) {
				best_duplicate = array[i];
				best_second_index = j;
			}
		}
	}

	return best_duplicate; 
}

// O(n) time O(n) space
int firstDuplicateValue(vector<int> array) { 
	
	int n = array.size();
	unordered_set<int> seen;
	
	for(int i = 0; i < n; i++) {
		int current = array[i];
		if(seen.find(current) != seen.end())
			return current;
		seen.insert(current);
	}

	return -1; 
}

// O(n) time, constant space
int firstDuplicateValue(vector<int> array) { 
	
	int n = array.size();
	
	for(int i = 0; i < n; i++) {
		int current = array[i];
		int current_abs = abs(current);
		if(array[current_abs-1] < 0) 
			return abs(current);
		array[current_abs - 1] *= -1;
	}
	return -1; 
}

