// Given a binary tree, find its max diameter
// O(n) time, O(d) space where n is the number of nodes and 
// d is the depth of the tree.


class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int inner(BinaryTree *tree, int& maximum) {
	
	if(!tree) return 0;
	
	int max_left_depth = tree->left ? inner(tree->left, maximum) + 1 : 0;
	int max_right_depth = tree->right ? inner(tree->right, maximum) + 1 : 0;
	
	int max_path_length = max_left_depth + max_right_depth;
	
	if(maximum < max_path_length) maximum = max_path_length;
	
	return std::max(max_left_depth, max_right_depth);
}

int binaryTreeDiameter(BinaryTree *tree) {

	int maximum = 0;
	
	inner(tree, maximum);
	
  return maximum;
}
