#include <string>
#include <vector>
using namespace std;

// You are given a string s of even length.Split this string into two halves of equal lengths, 
// and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
// Notice that s contains uppercase and lowercase letters.

// Return true if a and b are alike.Otherwise, return false.


class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int firstHalfVowelCount = 0;
        int secondHalfVowelCount = 0;
        int halfwayIndex = s.length() / 2;
        vector<char> vowels{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

        for (int index = 0; index < halfwayIndex; index++)
        {
            if (find(vowels.begin(), vowels.end(), s[index]) != vowels.end())
            {
                firstHalfVowelCount++;
            }
            if (find(vowels.begin(), vowels.end(), s[index + halfwayIndex]) != vowels.end())
            {
                secondHalfVowelCount++;
            }
        }

        if (firstHalfVowelCount == secondHalfVowelCount) 
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};