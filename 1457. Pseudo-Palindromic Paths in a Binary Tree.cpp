//Given a binary tree where node values are digits from 1 to 9. 
// A path in the binary tree is said to be pseudo - palindromic if at least one permutation of the node values in the path is a palindrome.

//Return the number of pseudo - palindromic paths going from the root node to leaf nodes.


//Constraints:
//
//The number of nodes in the tree is in the range[1, 105].
//1 <= Node.val <= 9

using namespace std;
#include <unordered_map>
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
    int totalPaths = 0;

    int pseudoPalindromicPaths(TreeNode* root)
    {
        unordered_map<int, int> valCount;
        countPalindromes(root, valCount);
        return totalPaths;
    }

    void countPalindromes(struct TreeNode* node, unordered_map<int, int> valCount)
    {
        if (node == nullptr) {
            return;
        }

        valCount[node->val]++;

        if (node->left == nullptr && node->right == nullptr) {
            int oddCount = 0;
            int evenCount = 0;

            for (auto i = valCount.begin(); i != valCount.end(); i++) {
                if (i->second % 2 == 0) {
                    evenCount++;
                }
                else {
                    oddCount++;
                }
            }

            if (oddCount > 1) {
                return;
            }

            totalPaths++;
            return;
        }

        countPalindromes(node->left, valCount);
        countPalindromes(node->right, valCount);

        return;
    }
};