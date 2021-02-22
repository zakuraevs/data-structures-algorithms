// Given a binary tree, invert all of its nodes,
// i.e. switch all left and right children.
// O(n) time O(d) space where n is the number of nodes and d
// is the depth of the tree.


#include <vector>
#include <queue>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

// Recursive
void invertBinaryTree(BinaryTree *tree) {
  
	if(!tree) return;
	
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
	
	BinaryTree* temporary = tree->left;
	tree->left = tree->right;
	tree->right = temporary;
	
	return;
}

// Iterative
void invertBinaryTree(BinaryTree *tree) {
  
	std::queue <BinaryTree*> unvisited;
	
	unvisited.push(tree);
	
	while(!unvisited.empty()) {
		
		BinaryTree* current = unvisited.front();
		unvisited.pop();
		
		if(current->left)
			unvisited.push(current->left);
		
		if(current->right)
			unvisited.push(current->right);
		
		BinaryTree* temporary = current->left;
		current->left = current->right;
		current->right = temporary;
	}
	
	return;
}
