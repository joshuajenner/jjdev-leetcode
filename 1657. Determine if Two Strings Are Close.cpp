#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//Two strings are considered close if you can attain one from the other using the following operations :
//
//Operation 1 : Swap any two existing characters.
//For example, abcde->aecdb
//Operation 2 : Transform every occurrence of one existing character into another existing character, and do the same with the other character.
//For example, aacabb->bbcbaa(all a's turn into b's, and all b's turn into a's)
//You can use the operations on either string as many times as necessary.
//
//Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

//Constraints:
//
//1 <= word1.length, word2.length <= 105
//word1 and word2 contain only lowercase English letters.


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> charMap1(26, 0);
        vector<int> charMap2(26, 0);

        if (word1.length() != word2.length()) {
            return false;
        }

        for (int index = 0; index < word1.length(); index++) 
        {
            charMap1[word1[index] - 'a']++;
            charMap2[word2[index] - 'a']++;
        }

        for (int index = 0; index < 26; index++) 
        {
            if ((charMap1[index] == 0) != (charMap2[index] == 0))
            {
                return false;
            }
        }

        sort(charMap1.begin(), charMap1.end());
        sort(charMap2.begin(), charMap2.end());

        if (charMap1 != charMap2) 
        {
            return false;
        }

        return true;
    }
};