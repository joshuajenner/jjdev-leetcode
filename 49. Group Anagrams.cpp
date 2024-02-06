//Given an array of strings strs, group the anagrams together.You can return the answer in any order.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
//typically using all the original letters exactly once.


#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> anagrams;
        vector<unordered_map<char, int>> uniqueLetters;

        for (string str: strs)
        {
            unordered_map<char, int> strMap;
            for (char c : str)
            {
                strMap[c]++;
            }
            
            int index = -1;
            for (int l = 0; l < uniqueLetters.size(); l++)
            {
                if (uniqueLetters[l] == strMap) {
                    index = l;
                    break;
                }
            }

            if (index == -1) 
            {
                anagrams.push_back(vector<string>{ str });
                uniqueLetters.push_back(strMap);
            }
            else
            {
                anagrams[index].push_back(str);
            }
        }

        return anagrams;
    }
};