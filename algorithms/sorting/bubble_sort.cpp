//O(n^2) time, constant space

#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  
	int n = array.size();
	bool sorted = false;
	
	while(!sorted) {
		sorted = true;
		for(int i = 0; i < n-1; i++) {
			if(array[i] > array[i+1]) {
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				sorted = false;
			}
		}
	}
	
  return array;
}
