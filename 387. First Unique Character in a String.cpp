//Given a string s, find the first non - repeating character in it and return its index.
//If it does not exist, return -1.

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> lettersMap;
        int uniqueIndex = -1;

        for (int index = 0; index < s.length(); index++)
        {
            if (lettersMap.find(s[index]) == lettersMap.end()) 
            {
                lettersMap[s[index]] = index;
            }
            else
            {
                lettersMap[s[index]] = -1;
            }
        }

        for (auto& letter: lettersMap) 
        {
            if (uniqueIndex == -1 || (letter.second != -1 && letter.second < uniqueIndex)) {
                uniqueIndex = letter.second;
            }
        }

        return uniqueIndex;
    }
};