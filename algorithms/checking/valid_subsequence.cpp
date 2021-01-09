// Given two arrays of integers, checki if second is a valid
// Subsequence of the first
// O(n) time, constant space

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  
	int subsequence_index = 0;
	
	for(int i = 0; i < array.size(); i++) {
		if(array[i] == sequence[subsequence_index]) {
			subsequence_index++;
			if(subsequence_index == sequence.size()) return true;
		}
	}
	
	
	
  return false;
}
