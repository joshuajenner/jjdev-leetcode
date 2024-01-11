#include <cstdlib>
#include <utility>
using namespace std;

// Given the root of a binary tree, find the maximum value v for which 
// there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    int findMaxDiff(TreeNode* root, int min, int max) {
        if (root == nullptr) {
            return std::abs(min - max);
        }

        min = std::min(min, root->val);
        max = std::max(max, root->val);

        int left = findMaxDiff(root->left, min, max);
        int right = findMaxDiff(root->right, min, max);

        return std::max(left, right);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val, root->val);
    }
};