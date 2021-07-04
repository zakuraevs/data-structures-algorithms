// Given a singly linked list, remove the kth node from the end.
// If the node is the head, update its value instead of just removing it.
// O(n) time, O(1) space where n is the size of the list.

#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  
	// Calculate length = n by iterating O(n)
	// Iterate again, until we hit position n - k ( - 1)?
	
	size_t n = 0;
	LinkedList* current = head;
	
	while (current) {
		current = current->next;
		n++;
	}
	
	int index_of_removal = n - k;
	
	if (index_of_removal == 0) {
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	
	current = head->next;
	LinkedList* previous = head;
	int position = 1;
	
	while (position < index_of_removal) {
		previous = current;
		current = current->next;
		position++;
	}
	
	previous->next = current->next;
	current->next = nullptr;
}