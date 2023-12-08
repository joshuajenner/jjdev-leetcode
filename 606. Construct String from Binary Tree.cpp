#include <string>
#include <iostream>
using namespace std;

// Given the root of a binary tree, 
// construct a string consisting of parenthesis and integers from a binary tree 
// with the preorder traversal way, and return it.

// Omit all the empty parenthesis pairs that do not affect the one - to - one mapping relationship 
// between the string and the original binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

string tree2str(TreeNode* root);

string tree2str(TreeNode* root)
{
    string returnString = "";
    extractByPreorder(root, &returnString);
    return returnString;
}

void extractByPreorder(struct TreeNode* node, string* buildString)
{
    if (node == NULL) {
        return;
    }

    *buildString += to_string(node->val);

    if (node->left || node->right)
    {
        *buildString += "(";
        extractByPreorder(node->left, buildString);
        *buildString += ")";
    }

    if (node->right)
    {
        *buildString += "(";
        extractByPreorder(node->right, buildString);
        *buildString += ")";
    }
}

