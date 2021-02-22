#include <iostream>

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

int findLargest(BinaryTreeNode* rootNode)
{
    // We are going to traverse one node at a time
    BinaryTreeNode* current = rootNode;
    // While there is a larger node
    while(current->right_)
    {
        current = current->right_;
    }
    return current->value_;
}

int findSecondLargest( BinaryTreeNode* rootNode)
{
    // We are going to traverse the tree. Current is the node we're looking at.
    BinaryTreeNode* current = rootNode;
    
    // If root is the largest 
    if(!current->right_) 
    {
        // If root is the only node
        if(!current->left_) 
            throw invalid_argument("not enough nodes");
        // Otherwise return the largest node in left subtree of root
        return findLargest(current->left_);
    }
    
    // This is the return value
    int res = rootNode->value_;
    
    // While we have a value greater than current
    while(current->right_) 
    {
        
        // The right child of current
        BinaryTreeNode* right = current->right_;
        
        // If the right child has no right child, i.e. right is the largest of all
        if(!right->right_) {
            // If it has a left child (subtree), we find the largest node there
            if(right->left_)
                res = findLargest(right->left_);
            // If not, then current is our target
            else
                res = current->value_;
            // Either way, we are done
            break;
        }
        // If we are not done, keep looking
        current = current->right_;
    }
    // Return what we assigned to res
    return res;
}
