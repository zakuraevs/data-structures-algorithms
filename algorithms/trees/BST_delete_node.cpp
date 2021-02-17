// Given a BST and a value, delete the first node with that value if possible, and return the tree root.
// O(H) time, constant space where H is the hight of the tree. equal to logn where n is the size of the tree,
// if the tree is balanced.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // Trackers of current node and its parent
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        
        // If given an empty tree, return it
        if(!current) return nullptr;
        
        // Run loop until desired node is found and deleted, or not found
        while(true) 
        {
            // We need to look left
            if(current->val > key) 
            {
                // If desired node is not in the tree
                if(!current->left) break;
                // Otherwise
                parent = current;
                current = current->left;
            } 
            // We need to look right
            else if(current->val < key)
            {
                // If desired node is not in the tree
                if(!current->right) break;
                // Otherwise
                parent = current;
                current = current->right;
            }
            // We found the key to be deleted
            else
            {
                // No children
                if(!current->left && !current->right)
                {
                    // If root is the only node, we're not deleting it.
                    if(!parent) return nullptr;
                    // Current is a left child
                    if(current->val < parent->val)
                        parent->left = nullptr;
                    // Current is a right child
                    else
                        parent->right = nullptr;
                }
                // One child
                else if(current->left && !current->right)
                {
                    // Check if current is root
                    if(!parent) 
                    {
                        current->val = current->left->val;
                        current->right = current->left->right;
                        current->left = current->left->left; 
                    }
                    // Otherwise simple procedure
                    else
                    {
                       if(current->val < parent->val)
                            parent->left = current->left;
                        else
                            parent->right = current->left;
                    }
                }
                else if(!current->left && current->right)
                {
                    if(!parent) 
                    {
                        current->val = current->right->val;
                        current->left = current->right->left;
                        current->right = current->right->right;
                    }
                    else
                    {
                       if(current->val < parent->val)
                            parent->left = current->right;
                        else
                            parent->right = current->right;
                    }
                }
                // Two children
                else
                {
                    // First, need to find the smallest value in left subree of current
                    TreeNode* sub_current = current->right;
                    TreeNode* sub_parent = current;
                    while(sub_current->left) 
                    {
                        sub_parent = sub_current;
                        sub_current = sub_current->left;
                    }
                    
                    int smallest_right_value = sub_current->val;
                    
                    // Now we have the value of the smallest. We place it into node
                    // to be removed, and then deal with sub_current
                    if(sub_parent != current)
                        sub_parent->left = sub_current->right;
                    else 
                        sub_parent->right = sub_current->right;
                    current->val = smallest_right_value;
                }
                break;
            }
        }
        return root;
        
    }
};