//You are given two strings order and s.All the characters of order are unique and were sorted in some custom order previously.
//
//Permute the characters of s so that they match the order that order was sorted.More specifically, 
//if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//
//Return any permutation of s that satisfies this property.

using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string customSortString(string order, string s)
    {
        int orderIndex = 0;

        for (char o : order) {
            vector<int> indexMap;

            for (int index = orderIndex; index < s.length(); index++)
            {
                if (s[index] == o) {
                    indexMap.push_back(index);
                }
            }

            for (int i: indexMap)
            {
                char temp = s[orderIndex];
                s[orderIndex] = s[i];
                s[i] = temp;
                orderIndex++;
            }
        }

        return s;
    }
};