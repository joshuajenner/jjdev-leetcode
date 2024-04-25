// You are given a string s consisting of lowercase letters and an integer k. 
// We call a string t ideal if the following conditions are satisfied:

// t is a subsequence of the string s.
// The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
// Return the length of the longest ideal string.

// A subsequence is a string that can be derived from another string by deleting some or no characters 
// without changing the order of the remaining characters.

// Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order
// of 'a' and 'z' is 25, not 1.

#include <string>
#include <algorithm>

class Solution {
public:
    int c2i(const char& c)
    {
        return c - '0';
    }

    int longestIdealString(std::string s, int k) 
    {
        char lastChar = '0';
        int answer = 0;

        for (char c: s) 
        {
            if (lastChar != '0')
            {
                if (std::abs(c2i(lastChar) - c2i(c)) <= k)
                {
                    lastChar = c;
                    answer += 1;
                }
            }
            else
            {
                lastChar = c;
                answer += 1;
            }
        }

        return answer;
    }
};