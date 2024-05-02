// Given a 0-indexed string word and a character ch, reverse the segment of word 
// that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). 
// If the character ch does not exist in word, do nothing.

// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment 
// that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
// Return the resulting string.

#include <string>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) 
    {
        std::string reversed = "";
        bool charFound = false;

        for (int i = 0; i < word.size(); i++) 
        {
            reversed = word[i] + reversed;

            if (ch == word[i]) 
            {
                reversed += word.substr(i + 1, word.size() - i + 1);
                charFound = true;
                break; 
            }
        }

        if (!charFound)
        {
            return word;
        }

        return reversed;
    }
};