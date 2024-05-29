// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by 
// deleting some (can be none) of the characters without disturbing the relative positions 
// of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

#include <string>

bool isSubsequence(std::string s, std::string t) 
{
    if (s == "") 
    {
        return true;
    }

    int sIndex = 0;
    int tIndex = 0;

    int sMax = s.size();
    int tMax = t.size();

    while (sIndex < sMax || tIndex < tMax) 
    {
        if (s[sIndex] == t[tIndex])
        {
            if (sIndex == sMax - 1) 
            {
                return true;
            }

            sIndex++;
            tIndex++;
        }
        else
        {
            if (tIndex >= tMax - 1) 
            {
                return false;
            }
            tIndex++;
        }
    }

    return false;
}