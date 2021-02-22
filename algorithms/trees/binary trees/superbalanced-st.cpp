#include <iostream>
#include <memory>
#include <limits.h>

using namespace std;

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

// Recursive (2 functions below)
bool traverse(const BinaryTreeNode* current, int &deepest, int &nearest, int depth) 
{
    if(!current->left_ && !current->right_) {
        if(depth > deepest)
            deepest = depth;
        if(depth < nearest)
            nearest = depth;
    }
    
    if(current->left_)
        traverse(current->left_, deepest, nearest, depth+1);
    if(current->right_)
        traverse(current->right_, deepest, nearest, depth+1); 
        
    return deepest - nearest < 2;    
}

bool isBalanced(const BinaryTreeNode* treeRoot)
{
    int deepest = 0;
    int nearest = INT_MAX;

    return traverse(treeRoot, deepest, nearest, 0);
}

// Iterative
bool isBalanced(const BinaryTreeNode* treeRoot)
{
    if(!treeRoot)
        return true;
        
    int deepest = 0;
    int nearest = INT_MAX;
    int depth = 0;
    std::stack<pair<const BinaryTreeNode*, int>> nodes;
    nodes.push(make_pair(treeRoot, 0));
    
    while(!nodes.empty()) 
    {
        if(deepest - nearest > 2) return false;
       
        const BinaryTreeNode* current = nodes.top().first;
        depth = nodes.top().second;
        nodes.pop();
       
        if(!current->left_ && !current->right_) {
            if(depth > deepest)
                deepest = depth;
            if(depth < nearest)
                nearest = depth;
        }
        
        if(current->right_)
            nodes.push(make_pair(current->right_, depth+1));
            
        if(current->left_)
            nodes.push(make_pair(current->left_, depth+1));
    }
    
    return deepest - nearest < 2;
}