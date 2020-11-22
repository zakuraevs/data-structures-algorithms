//given a BST, the rangeSumBST method returns the sum
// of al lnodes that are within the range [low, high]

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {

    int result = 0;

    if (root) {
        if (root->val >= low && root->val <= high)
            result += root->val;

        if (root->val < high)
            result += rangeSumBST(root->right, low, high);

        if (root->val > low)
            result += rangeSumBST(root->left, low, high);
    }
    return result;
}
