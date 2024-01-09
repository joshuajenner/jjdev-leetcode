#include <queue>
using namespace std;

// Given the root node of a binary search tree and two integers low and high, 
// return the sum of values of all nodes with a value in the inclusive range [low, high].


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


int rangeSumBST(TreeNode* root, int low, int high);

int rangeSumBST(TreeNode* root, int low, int high)
{
	int sum = 0;
	queue<TreeNode*> queue;
	queue.push(root);

	while (queue.size() > 0) 
	{
		TreeNode* node = queue.front();
		int checkValue = node->val;

		if (checkValue >= low && checkValue <= high) 
		{
			sum += checkValue;
		}

		queue.pop();
		if (node->left != NULL) 
		{
			queue.push(node->left);
		}
		if (node->right != NULL) 
		{
			queue.push(node->right);
		}
	}

	return sum;
}


//// A Binary Tree Node
//struct Node {
//    int data;
//    struct Node* left, * right;
//};
//
//// Iterative method to find height of Binary Tree
//void printLevelOrder(Node* root)
//{
//    // Base Case
//    if (root == NULL)
//        return;
//
//    // Create an empty queue for level order traversal
//    queue<Node*> q;
//
//    // Enqueue Root and initialize height
//    q.push(root);
//
//    while (q.empty() == false) {
//
//        // Print front of queue and remove it from queue
//        Node* node = q.front();
//        cout << node->data << " ";
//        q.pop();
//
//        // Enqueue left child
//        if (node->left != NULL)
//            q.push(node->left);
//
//        // Enqueue right child
//        if (node->right != NULL)
//            q.push(node->right);
//    }
//}