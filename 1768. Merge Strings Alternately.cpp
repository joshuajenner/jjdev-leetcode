#include <string>
using namespace std;


// You are given two strings word1 and word2.Merge the strings by adding letters in alternating order, 
// starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.


string mergeAlternately(string, string);

string mergeAlternately(string word1, string word2)
{
    int longestWordLength = max(word1.length(), word2.length());
    string returnString = "";
    for (int charIndex = 0; charIndex < longestWordLength; charIndex++)
    {
        if (charIndex < word1.length())
        {
            returnString.push_back(word1[charIndex]);
        }
        if (charIndex < word2.length()) 
        {
            returnString.push_back(word2[charIndex]);
        }
    }
    return returnString;
}