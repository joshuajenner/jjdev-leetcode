#include <string>
using namespace std;

// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non - space characters only.

int lengthOfLastWord(string s);

int lengthOfLastWord(string s)
{
    bool lastLetterFound = false;
    int wordLength = 0;
    for (int index = s.length() - 1; index >= 0; index--)
    {
        if (s[index] != ' ')
        {
            wordLength++;
            if (!lastLetterFound)
            {
                lastLetterFound = true;
            }
        }
        else
        {
            if (lastLetterFound)
            {
                return wordLength;
            }
        }
    }
    return wordLength;
}