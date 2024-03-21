//Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) 
    {
        return ListReversal(head, nullptr);
    }

    ListNode* ListReversal(ListNode* currNode, ListNode* prevNode) 
    {
        if (currNode == nullptr) {
            return prevNode;
        }

        ListNode* nextCopy = currNode->next;
        currNode->next = prevNode;
        return ListReversal(nextCopy, currNode);
    }
};