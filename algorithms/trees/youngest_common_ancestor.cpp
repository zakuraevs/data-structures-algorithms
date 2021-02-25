// Given a tree root and two nodes in the tree,
// find the youngest common ancestor of the two nodes.
// Nodes are also their own ancestors.
// O(d) time, O(1) space where d is the maximal depth of the tree.

#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  
	AncestralTree* one_youngest_common = descendantOne;
	AncestralTree* two_youngest_common = descendantTwo;
	
	int one_height = -1;
	int two_height = -1;
	
	AncestralTree* current = descendantOne;
	
	// O(h)
	while (current) {
		one_height++;
		current = current->ancestor;
	}
	current = descendantTwo;
	// O(h)
	while (current) {
		two_height++;
		current = current->ancestor;
	}

	// O(h)
	while (one_height > two_height) {
		one_youngest_common = one_youngest_common->ancestor;
		one_height--;
	} 
	// O(h)
	while (two_height > one_height) {
		two_youngest_common = two_youngest_common->ancestor;
		two_height--;
	}
	
	// O(h)
	while (one_youngest_common->name != two_youngest_common->name) {
		one_youngest_common = one_youngest_common->ancestor;
		two_youngest_common = two_youngest_common->ancestor;
	}
	
	return one_youngest_common;
}
