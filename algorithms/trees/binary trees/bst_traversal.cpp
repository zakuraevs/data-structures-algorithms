// Given a valid BST,
// write methods for inorder, preorder and postorder traversal
// O(n) time, O(n) space for all 3, where n is the number of nodes. 

// Inorder: left, node, right
// Preorder: node, left, right
// Postorder: left, right, node

#include <vector>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};

void inOrderTraverse(BST *tree, vector<int> &array) {
  
	if(tree->left)
		inOrderTraverse(tree->left, array);
		
	array.push_back(tree->value);
	
	if(tree->right)
		inOrderTraverse(tree->right, array);
	
}

void preOrderTraverse(BST *tree, vector<int> &array) {
  
	array.push_back(tree->value);
	
	if(tree->left)
		preOrderTraverse(tree->left, array);
	
	if(tree->right)
		preOrderTraverse(tree->right, array);
	
}

void postOrderTraverse(BST *tree, vector<int> &array) {
  
	if(tree->left)
		postOrderTraverse(tree->left, array);
	
	if(tree->right)
		postOrderTraverse(tree->right, array);
	
	array.push_back(tree->value);
}