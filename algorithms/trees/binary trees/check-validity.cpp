// This algorithm checks whether a binary tree steming from a given root node
// a valide binary tree. O(n) time where n is the number of nodes and O(h) space
// where h is the height of the tree. In the unbalanced worst case h = n and in the
// balanced worst case h = logn.

#include <iostream>
#include <memory>
#include <stack>
#include <limits.h>

using namespace std;

// Class for a tree node
class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

// Algorithm for checking the tree
bool isBinarySearchTree(const BinaryTreeNode* root)
{
    // Initialize a stack for DFS. <node, lowerLimit, upperLimit>
    std::stack<std::tuple<const BinaryTreeNode*, int, int>> nodes;
    // No limits for the root
    nodes.push(std::make_tuple(root, INT_MIN, INT_MAX));
    
    while(!nodes.empty()) 
    {
        // Take LIFO node 
        std::tuple<const BinaryTreeNode*, int, int> top = nodes.top();
        const BinaryTreeNode* current = std::get<0>(top);
        int lower = std::get<1>(top);
        int upper = std::get<2>(top);
        nodes.pop();
        
        // If the current node is outside its limits, fail
        if(current->value_ >= upper || current->value_ <= lower)
            return false;
        
        // If there is a left child, push it to the stack
        // Lower limit is the lower limit of the current node. This ensures that a node in
        // the right branch is not smaller than the root for example.
        // Upper limit is the current node.
        if(current->left_) 
        {
            nodes.push(std::make_tuple(current->left_, lower, current->value_));
        } 
        // If there is a right child, push it to the stack
        // Lower limit is the current node
        // Upper limit it the upper limit of the current node. This ensure that a node
        // in the left branch is not greater than the root for example.
        if(current->right_) 
        {
            nodes.push(std::make_tuple(current->right_, current->value_, upper));
        } 
    }
    
    return true;
}

// Alternative for huge values:
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
#include<stack>
#include <limits.h>

class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        // node, lower, upper
        std::stack<std::tuple<const TreeNode*, long long int, long long int>> nodes;
        nodes.push(std::make_tuple(root, LLONG_MIN, LLONG_MAX));
        
        while(!nodes.empty())
        {
            std::tuple<const TreeNode*, long long int, long long int> current = nodes.top();
            nodes.pop();
            const TreeNode* current_node = std::get<0>(current);
            long long int lower_limit = std::get<1>(current);
            long long int upper_limit = std::get<2>(current);
            
            if(current_node->val <= lower_limit || current_node->val >= upper_limit) {
                return false;
            }
                
            if(current_node->left != nullptr) {
                nodes.push(std::make_tuple(current_node->left, lower_limit, current_node->val));
            }
            if(current_node->right != nullptr){
                nodes.push(std::make_tuple(current_node->right, current_node->val, upper_limit));
            }   
        }
        
        return true;
    }
};
