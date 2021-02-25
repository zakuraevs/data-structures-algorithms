// Given a tree root and two nodes in the tree,
// find the youngest common ancestor of the two nodes.
// Nodes are also their own ancestors.

// Access to ancestors, more than two children possible
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

// No access to ancestors, binary tree
// O(n) time and space where n is the number of nodes.

#include <stack>
#include <unordered_map>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int p_depth;
        int q_depth;
        bool p_found = false;
        bool q_found = false;
        stack<pair<TreeNode*, int>> unvisited;
        unordered_map<TreeNode*, TreeNode*> parents;
        
        unvisited.push(make_pair(root,0));
        
        while (!unvisited.empty() || (!p_found && !q_found)) {
                        
            pair<TreeNode*, int> current = unvisited.top();
            unvisited.pop();
            TreeNode* current_node = current.first;
            int current_depth = current.second;
            
            if (current_node->val == p->val) {
                p_depth = current_depth;
                p_found = true;
            }
                
            if (current_node->val == q->val) {
                q_depth = current_depth;
                q_found = true;
            }
            
            if (current_node->right) {
                unvisited.push(make_pair(current_node->right, current_depth+1));
                parents[current_node->right] = current_node;
            }
            if (current_node->left) {
                unvisited.push(make_pair(current_node->left, current_depth+1));
                parents[current_node->left] = current_node;
            }
        }

        TreeNode* p_youngest_common = p;
        TreeNode* q_youngest_common = q;

        while (p_depth > q_depth) {
            p_youngest_common = parents[p_youngest_common];
            p_depth--;
        } 

        while (q_depth > p_depth) {
            q_youngest_common = parents[q_youngest_common];
            q_depth--;
        }

        while (p_youngest_common->val != q_youngest_common->val) {
            //cout << "p_youngest_common->val != q_youngest_common->val" << endl;
            p_youngest_common = parents[p_youngest_common];
            q_youngest_common = parents[q_youngest_common];
        }

        return p_youngest_common;
        
    }
};
