// Given a binary tree and a node, find the successor
// of that node in in-order traversal, or nullptr if node
// is last.

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// O(h) time, O(1) space where h is the height of the tree
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	
	BinaryTree* current = nullptr;
	
	if (node->right) {
		current = node->right;
		while (current->left)
			current = current->left;
	} else {
		current = node;
		while (current->parent && current->parent->right == current)
			current = current->parent;
		current = current->parent;
	}
	
	return current;
}

// O(n) time and space, where n is the number of nodes in the tree.
void in_order_traverse(BinaryTree *tree, std::vector<BinaryTree*>& all_nodes) {
	
	if (tree->left) {
		in_order_traverse(tree->left, all_nodes);
	}
	
	all_nodes.push_back(tree);
	
	if (tree->right) {
		in_order_traverse(tree->right, all_nodes);
	}
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	
	std::vector<BinaryTree*> all_nodes;
	
	in_order_traverse(tree, all_nodes);
	
	int n = all_nodes.size();
	
	for (int i = 0; i < n; i++) {
		if (all_nodes[i] == node && i < n - 1) {
			return all_nodes[i + 1];
		}
	}
	
  return nullptr;
}
