//Given a string s, sort it in decreasing order based on the frequency of the characters.
//The frequency of a character is the number of times it appears in the string.
//
//Return the sorted string.If there are multiple answers, return any of them.


#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s)
    {
        string sorted = "";
        unordered_map<char, int> charCount;
        int maxCount = 0;

        for (char c: s) {
            charCount[c]++;
            if (charCount[c] > maxCount) {
                maxCount++;
            }
        }

        for (int count = maxCount; count > 0; count--) 
        {
            for (auto& counts : charCount)
            {
                if (count == counts.second)
                {
                    sorted += string(counts.second, counts.first);
                }
            }
        }

        return sorted;
    }
};