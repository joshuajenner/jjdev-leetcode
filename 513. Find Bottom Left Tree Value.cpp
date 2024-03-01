//Given the root of a binary tree, return the leftmost value in the last row of the tree.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int leftMost = 0;

    int findBottomLeftValue(TreeNode* root) 
    {
        GetLeftMostValue(root, 0);
        return leftMost;
    }

    void GetLeftMostValue(TreeNode* node, int level) 
    {
        if (node == nullptr) 
        {
            return;
        }
    }
};