#include <vector>
using namespace std;

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root);

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> returnVector;
    InorderVector(root, returnVector);
    return returnVector;
}

void InorderVector(struct TreeNode* node, vector<int>& buildVector)
{
    if (node == NULL)
        return;

    InorderVector(node->left, buildVector);
    buildVector.push_back(node->val);
    InorderVector(node->right, buildVector);
}