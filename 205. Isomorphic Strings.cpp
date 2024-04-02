//Given two strings s and t, determine if they are isomorphic.
//
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters.
//No two characters may map to the same character, but a character may map to itself.

#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> sMap;
        std::unordered_map<char, char> tMap;

        for (int i = 0; i < s.size(); i++)
        {
            if (sMap.count(s[i]) || tMap.count(t[i]))
            {
                if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])
                {
                    return false;
                }
            }
            else
            {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            }
        }

        return true;
    }
};