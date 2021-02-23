// Given an array of integers, where each elements shows
// the next index to go to, check whether the array thus
// only contains a single cycle of length n.
// O(n) time, constant space >:)


using namespace std;

int get_next_index(int current, int delta, int n) {
	int next_ind = (current + delta) % n;
	return next_ind >= 0 ? next_ind : next_ind + n;
}

bool hasSingleCycle(vector<int> array) {
  
	int n = array.size();
	int index = 0;
	int elements_visited = 0;
	
	while (elements_visited < n) {
		if (elements_visited > 0 && index == 0) 
			return false;
		elements_visited++;
		index = get_next_index(index, array[index], n);
	}
  return index == 0;
}



