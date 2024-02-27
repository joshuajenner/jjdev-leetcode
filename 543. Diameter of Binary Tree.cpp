//Given the root of a binary tree, return the length of the diameter of the tree.
//
//The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
//This path may or may not pass through the root.
//
//The length of a path between two nodes is represented by the number of edges between them.

using namespace std;
#include <algorithm> 
#include <iostream>

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
    int diameterOfBinaryTree(TreeNode* root) {
        return GetLongestPath(root, 0);
    }

    int GetLongestPath(TreeNode* node, int longestPath) {
        if (node == nullptr) {
            return longestPath;
        }

        int maxPath = GetMaxEdgesUnderNode(node->left, 0) + GetMaxEdgesUnderNode(node->right, 0);

        return max(maxPath, max(GetLongestPath(node->left, longestPath), GetLongestPath(node->right, longestPath)));
    }

    int GetMaxEdgesUnderNode(TreeNode* node, int level) {
        if (node == nullptr) {
            return level;
        }
        level++;

        return max(GetMaxEdgesUnderNode(node->left, level), GetMaxEdgesUnderNode(node->right, level));
    }
};