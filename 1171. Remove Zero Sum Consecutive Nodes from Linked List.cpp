//Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 
//until there are no such sequences.
//
//After doing so, return the head of the final linked list. You may return any such answer.


using namespace std;
#include <vector>

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> listVector;
        listToVector(listVector, head);

        int count = listVector.size();
        int zeroSum = 0;
        int firstNegIndex = -1;

        for (int index = 0; index < count; index++)
        {
            if (listVector[index] < 0)
            {
                zeroSum += listVector[index];
                listVector[index] = 0;

                if (firstNegIndex == -1)
                {
                    firstNegIndex = index;
                }
            }
            if ((listVector[index] < 0 || index == count-1) && firstNegIndex != -1)
            {
                for (int j = firstNegIndex - 1; j >= 0; j--)
                {
                    zeroSum += listVector[j];
                    listVector[j] = 0;
                    if (zeroSum == 0)
                    {
                        firstNegIndex = -1;
                        break;
                    }
                }
            }
        }

        ListNode* returnHead = nullptr;
        ListNode* currentNode = nullptr;

        for (int i: listVector)
        {
            if (i != 0)
            {
                if (returnHead == nullptr)
                {
                    ListNode* newNode = new ListNode(i);
                    returnHead = newNode;
                    currentNode = newNode;
                }
                else {
                    ListNode* newNode = new ListNode(i);
                    currentNode->next = newNode;
                    currentNode = newNode;
                }
            }
        }

        return returnHead;
    }

    void listToVector(vector<int> &vector, ListNode* node)
    {
        if (node == nullptr) {
            return;
        }

        vector.push_back(node->val);
        listToVector(vector, node->next);
    }
};