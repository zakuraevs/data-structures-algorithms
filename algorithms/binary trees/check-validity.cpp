#include <iostream>
#include <stack>
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

bool isBinarySearchTree(const BinaryTreeNode* root)
{
    std::stack<std::tuple<const BinaryTreeNode*, int, int>> nodes;
    nodes.push(std::make_tuple(root, INT_MIN, INT_MAX));
    
    while(!nodes.empty()) 
    {
        std::tuple<const BinaryTreeNode*, int, int> top = nodes.top();
        const BinaryTreeNode* current = std::get<0>(top);
        int lower = std::get<1>(top);
        int upper = std::get<2>(top);
        nodes.pop();
        
        if(current->value_ >= upper || current->value_ <= lower)
            return false;
        
        if(current->left_) 
        {
            nodes.push(std::make_tuple(current->left_, lower, current->value_));
        } 
        if(current->right_) 
        {
            nodes.push(std::make_tuple(current->right_, current->value_, upper));
        } 
    }
    
    return true;
}
