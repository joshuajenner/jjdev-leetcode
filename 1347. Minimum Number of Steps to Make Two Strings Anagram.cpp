#include <string>
#include <unordered_map>
#include <stdlib.h> 
using namespace std;

// You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
//
// Return the minimum number of steps to make t an anagram of s.
//
// An Anagram of a string is a string that contains the same characters with a different(or the same) ordering.

// Constraints:
//
// 1 <= s.length <= 5 * 104
// s.length == t.length
// s and t consist of lowercase English letters only.


class Solution {
public:
    int minSteps(string s, string t) 
    {
        int minimumSteps = 0;
        unordered_map<char, int> characterDifference;

        for (int index = 0; index < s.length(); index++) 
        {
            characterDifference[s[index]]++;
            characterDifference[t[index]]--;
        }

        for (auto& iter : characterDifference) 
        {
            minimumSteps += abs(iter.second);
        }

        return minimumSteps / 2;
    }
};