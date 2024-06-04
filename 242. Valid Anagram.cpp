#include <string>
#include <unordered_map>
using namespace std;

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

bool isAnagram(string, string);


bool isAnagram(string s, string t)
{
    if (s.length() == t.length())
    {
        unordered_map < char, int > countMap;
        for (int index = 0; index < s.length(); index++)
        {
            countMap[s[index]]++;
            countMap[t[index]]--;
        }
        for (auto& i: countMap)
        {
            if (i.second != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}