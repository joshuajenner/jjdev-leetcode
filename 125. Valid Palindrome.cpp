// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
// and removing all non-alphanumeric characters, it reads the same forward and backward. 
// Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

#include <string>

bool isPalindrome(std::string s) 
{
    int frontIndex = 0;
    int backIndex = s.size() - 1;

    char frontChar = s[frontIndex];
    char backChar = s[backIndex];

    while (frontIndex < backIndex) 
    {
        bool wasAdjusted = false;
        
        if (!isalnum(frontChar)) 
        {
            frontChar = s[++frontIndex];
            wasAdjusted = true;
        }

        if (!isalnum(backChar)) 
        {
            backChar = s[--backIndex];
            wasAdjusted = true;
        }

        if (wasAdjusted) {
            continue;
        }

        if (tolower(frontChar) != tolower(backChar)) 
        {
            return false;
        }

        frontChar = s[++frontIndex];
        backChar = s[--backIndex];
    }

    return true;
}