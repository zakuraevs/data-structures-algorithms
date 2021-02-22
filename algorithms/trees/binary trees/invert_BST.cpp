// Given a binary tree, invert all of its nodes,
// i.e. switch all left and right children.
// O(n) time O(d) space where n is the number of nodes and d
// is the depth of the tree.


#include <vector>
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

void invertBinaryTree(BinaryTree *tree) {
  
	if(!tree) return;
	
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
	
	BinaryTree* temporary = tree->left;
	tree->left = tree->right;
	tree->right = temporary;
	
	return;
}
