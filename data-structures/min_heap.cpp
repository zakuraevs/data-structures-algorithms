// A class representing a min heap data structure

#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }
	
	// Node at index i:
	// left child is at index i * 2 + 1
	// right child is at index i * 2 + 2
	// parent is at index (i-1) / 2

	// O(n)
  vector<int> buildHeap(vector<int> &vector) {
  	int last_parent_index = vector.size() - 2 / 2;
		for (int i = last_parent_index; i >= 0; i--) {
			siftDown(i, vector.size() - 1, vector);
		}
		return vector;
  }

	// O(logn)
  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    
		int left_child_index = currentIdx * 2 + 1;
		
		while (left_child_index <=  endIdx) {
			
			int right_child_index = left_child_index + 1;
			int index_of_smaller_child;
			
			if (right_child_index <= endIdx) {
				index_of_smaller_child = heap[left_child_index] < heap[right_child_index] ? 
				left_child_index : right_child_index;
			} else {
				index_of_smaller_child = left_child_index;
			}
			
			if (heap[currentIdx] > heap[index_of_smaller_child]) {
				int temp = heap[currentIdx];
				heap[currentIdx] = heap[index_of_smaller_child];
				heap[index_of_smaller_child] = temp;
				currentIdx = index_of_smaller_child;
				left_child_index = currentIdx * 2 + 1;
			} else {
				break;
			}
		}
  }

	// O(logn)
  void siftUp(int currentIdx, vector<int> &heap) {
		
		int parent_index = (currentIdx - 1) / 2;
		
		while (currentIdx > 0 && heap[currentIdx] < heap[parent_index]) {
			
			int temp = heap[currentIdx];
			heap[currentIdx] = heap[parent_index];
			heap[parent_index] = temp;
			
			currentIdx = parent_index;
			parent_index = (currentIdx - 1) / 2;
		}
  }

	// O(1)
  int peek() { 
		return heap.empty() ? -1 : heap[0];
	}

	// O(logn)
  int remove() {
		if (heap.empty()) return -1;
		int return_value = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap);
		return return_value;
  }

	// O(logn)
  void insert(int value) {
		heap.push_back(value);
		siftUp(heap.size() - 1, heap);
  }
};
