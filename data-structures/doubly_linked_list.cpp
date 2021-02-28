// A class representing a doubly linked list data structure.

using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

	// O(1)
  void setHead(Node *node) {		
		if (!head) {
			head = node;
			tail = node;
			return;
		}
		insertBefore(head, node);
  }

	// O(1)
  void setTail(Node *node) {
		if (!tail) {
			head = node;
			tail = node;
			return;
		}
		insertAfter(tail, node);
  }

	// O(1)
  void insertBefore(Node *node, Node *nodeToInsert) {
		
		if (nodeToInsert == head && nodeToInsert == tail) 
			return;
		
		remove(nodeToInsert);
		nodeToInsert->next = node;
		nodeToInsert->prev = node->prev;
		if (node->prev != nullptr)
			node->prev->next = nodeToInsert;
		else
			head = nodeToInsert;
		node->prev = nodeToInsert;
  }

	// O(1)
  void insertAfter(Node *node, Node *nodeToInsert) {
		
		if (nodeToInsert == head && nodeToInsert == tail) 
			return;
		
		remove(nodeToInsert);
		nodeToInsert->prev = node;
		nodeToInsert->next = node->next;
		if (node->next != nullptr)
			node->next->prev = nodeToInsert;
		else
			tail = nodeToInsert;
		node->next = nodeToInsert;
  }

	// O(p)
  void insertAtPosition(int position, Node *nodeToInsert) {
		
		if (position == 1) {
			setHead(nodeToInsert);
			return;
		}
		
		int curr_pos = 1;
		Node* current = head;
		
		while (current && curr_pos != position) {
			current = current->next;
			curr_pos++;
		}
		
		if (current)
			insertBefore(current, nodeToInsert);
		else
			setTail(nodeToInsert);
  }

	// O(n)
  void removeNodesWithValue(int value) {
		cout << "removing node with value" << endl;
		
		Node* current = head;
		
		while (current) {
			Node* temp = current->next;
			if (current->value == value)
				remove(current);
			current = temp;
		}
  }

	// O(1)
  void remove(Node *node) {
		cout << "removing node" << endl;
		
		if (node == head)
			head = head->next;
		if (node == tail)
			tail = tail->prev;
		
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		node->prev = nullptr;
		node->next = nullptr;
  }

	// O(n)
  bool containsNodeWithValue(int value) {
		cout << "checking if contains" << endl;
		Node* current = head;
		
		while (current) {
			if (current->value == value) 
				return true;
			current = current->next;
		}
		return false;
  }
};
