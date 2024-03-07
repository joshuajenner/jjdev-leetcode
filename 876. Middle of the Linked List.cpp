//Given the head of a singly linked list, return the middle node of the linked list.
//
//If there are two middle nodes, return the second middle node.

using namespace std;
#include <queue>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        queue<ListNode*> middleQueue;
        getMiddleNode(head, middleQueue, 0);
        return middleQueue.front();
    }

    void getMiddleNode(ListNode* node, queue<ListNode*> &middleQueue, int nodePos) 
    {
        if (node == nullptr)
        {
            return;
        }
        nodePos++;

        middleQueue.push(node);
        if (nodePos % 2 == 0)
        {
            middleQueue.pop();
        }

        getMiddleNode(node->next, middleQueue, nodePos);
    }
};