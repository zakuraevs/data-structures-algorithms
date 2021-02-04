#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val) {
		BST *new_node = new BST(val);
		BST *current = this;

		// We're going to traverse the tree starting at the
		// current node this, and find the right place for the new node.
		while(true) {

			// If new node is smaller than current, we're going to place it to the left.
			if(val < current->value) {
				// If current has no left child,
				// then we found the right place.
				if(!current->left) {
					current->left = new_node;
					break;
				}
				// Otherwise we keep looking to the left
				// And go to the next while iteration.
				else
				    current = current->left;

				// If new node is greater than or equal to current,
				// we're going to place it to the right.
			} else {
				// If current has no right child,
				// we simply place it to the right
				if(!current->right) {
					current->right = new_node;
					break;
				}
				// And if there is a right child, we keep looking.
				else
				    current = current->right;
			}
		}
    return *this;
  }

  bool contains(int val) {
		// We're going to traverse the tree and stop
		// when we find the target value or current node
		// has no children
		BST *current = this;

		while(true) {

			// Found target
			if(current->value == val)
				return true;

			// Target not in BST
			if((current->value > val && !current->left) ||
			   (current->value < val && !current->right))
			    return false;

			// Decide where to keep looking
			if(val < current->value)
			    current = current->left;
			else
			    current = current->right;
		}
    return false;
  }

  BST &remove(int val) {
		// First, make sure there is more than one node
		if(!left && !right)
			return *this;

		// Second, we're going to check if the node to be removed
		// is there at all. This function call is just done for
		// convenience and is suboptimal in terms of performance.
		if(!this->contains(val))
			return *this;

		BST *parent = this;
		BST *current = this;
		std::string direction;

		// Now let us traverse the tree and find the node to be removed
		// At this point we know for sure that the tree contains the desired value
		while(true) {

		    // If we found a node with desired value, then ...
		    if(current->value == val) {
		        // If current is a leaf node, we're simply deleting it
		        if(!current->left && !current->right) {
		            direction == "left" ? parent->left = NULL : parent->right = NULL;
		            // If current has one child, we simply set parent's child as child of current
		        }else if(!current->left){
                    direction == "left" ? parent->left = current->right : parent->right = current->right;
		        }else if(!current->right){
                    direction == "left" ? parent->left = current->left : parent->right = current->left;
                    // If the parent has two children, then
                }else{
                    // Find largest node in left subtree
                    BST *sub_parent = current;
                    BST *sub_current = current->left;

                    while(sub_current->right) {
                        sub_parent = sub_current;
                        sub_current = sub_current->right;
                    }

                    // We found the largest node in left subtree of current
                    if(sub_current->left) {
                        sub_parent->right = sub_current->left;
                    } else {
                        sub_parent->right = NULL;
                    }

                    current->value = sub_current->value;
		        }
		        break;
		    } else if(current->value > val) {
                parent = current;
                current = current->left;
                direction = "left";
		    } else {
                parent = current;
                current = current->right;
                direction = "right";
		    }
		}
		return *this;
  }
  
};
