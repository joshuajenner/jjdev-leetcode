//You are given two linked lists : list1 and list2 of sizes n and m respectively.
//
//Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
//
//The blue edges and nodes in the following figure indicate the result :

#include <iostream>;
using namespace std;

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode* nodeBeforeA = GetNodeByPos(list1, a - 1, 0);
        ListNode* nodeAfterB = GetNodeByPos(list1, b + 1, 0);
        ListNode* endOfList2 = GetEndNode(list2);

        nodeBeforeA->next = list2;
        endOfList2->next = nodeAfterB;

        return list1;
    }

    ListNode* GetEndNode(ListNode* node)
    {
        return node->next == nullptr ? node : GetEndNode(node->next);
    }

    ListNode* GetNodeByPos(ListNode* node, int targetPos, int currentPos)
    {
        return currentPos == targetPos ? node : GetNodeByPos(node->next, targetPos, currentPos + 1);
    }
};