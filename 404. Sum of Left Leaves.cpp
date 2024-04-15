
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {   
        int sum = 0;
        getLeftLeaves(root, sum);
        return sum;
    }

    void getLeftLeaves(TreeNode* node, int& sum) 
    {
        if (node == nullptr) 
        {
            return;
        }
        if (node->left != nullptr) {
            sum += node->left->val;
        }
        getLeftLeaves(node->left, sum);
        getLeftLeaves(node->right, sum);
    }
};