// Given an array of integers and a target value,
// Move all the elements in the array that equal to target
// To the end of the array in place, without regard for order
// of other elements
// O(n) time, constant space

#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  
	int n = array.size();
	int left = 0;
	int right = n - 1;
	
	while(left < right) {
		
		if(array[left] == toMove) {
			
			while(array[right] == toMove && left < right) {
				right--;
			}
			int temp = array[right];
			array[right] = array[left];
			array[left] = temp;
		}
		left++;
	}

  return array;
}