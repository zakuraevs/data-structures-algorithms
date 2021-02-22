// Given a valid BST, calculate the sum of 
// the depths of all the nodes
// O(n) time, O(n) space

#include <stack>

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

int nodeDepths(BinaryTree *root) {
  
	// node, depth
	stack<pair<BinaryTree*, int>> s;
	s.push(make_pair(root, 0));
	int sum = 0;
	
	while(!s.empty()) {
		
		BinaryTree *current = s.top().first;
		int current_depth = s.top().second;
		s.pop();
		sum += current_depth;
		
		if(current->left)
			s.push(make_pair(current->left, current_depth+1));
		if(current->right)
			s.push(make_pair(current->right, current_depth+1));
	}
  return sum;
}