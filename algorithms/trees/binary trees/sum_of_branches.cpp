// Given a valid BST, return a vector of integers,
// where each integer is the sum of elements on a branc of the BST
// O(n) time and space

#include <stack>

using namespace std;

// This is the class of the input root. Do not edit it.
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

vector<int> branchSums(BinaryTree *root) {
  
	stack<pair<BinaryTree*,int>> need_to_visit;
	//int current_sum = 0;
	vector<int> sums;
	
	need_to_visit.push(make_pair(root, root->value));
	
	while(!need_to_visit.empty()) {
		
		BinaryTree *current = need_to_visit.top().first;
		int sum = need_to_visit.top().second;
		need_to_visit.pop();
		//current_sum += current->value;
		
		if(current->left) {
			need_to_visit.push(make_pair(current->left, current->left->value + sum));
		}
		if(current->right) {
			need_to_visit.push(make_pair(current->right, current->right->value + sum));
		}
		if(!current->left && ! current->right) {
			sums.insert(sums.begin(), sum);
		}
	}
	
  return sums;
}
