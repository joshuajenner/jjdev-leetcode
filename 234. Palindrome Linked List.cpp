//Given the head of a singly linked list, 
//return true if it is a palindrome or false otherwise.

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
    bool isPalindrome(ListNode* head)
    {
        std::vector<int> listValues;
    
        while (head != nullptr) {
            listValues.push_back(head->val);
            head = head->next;
        }
    
        int size = listValues.size();
        for (int i = 0; i < size; i++)
        {
            if (listValues[i] != listValues[size - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};