using namespace std;

// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

int amountOfTime(TreeNode* root, int start);

int amountOfTime(TreeNode* root, int start)
{
	int timeNeeded = 0;
    int treeHeight = maxHeight(root);

    

	return timeNeeded;
}

int maxHeight(TreeNode* node)
{
    if (node == nullptr)
        return 0;
    else {
        int leftHeight = maxHeight(node->left);
        int rightHeight = maxHeight(node->right);
 
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}