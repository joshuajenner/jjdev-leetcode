//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

using namespace std;
#include <iostream>


//Definition for a binary tree node.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p != nullptr && q != nullptr) {
            return CheckNodes(p, q);
        }
        return false;
    }

    bool CheckNodes(struct TreeNode* node1, struct TreeNode* node2)
    {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }

        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        if (node1->val != node2->val) {
            return false;
        }

        return CheckNodes(node1->left, node2->left) && CheckNodes(node1->right, node2->right);
    }
};