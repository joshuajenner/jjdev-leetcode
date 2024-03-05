// Given a string s consisting only of characters 'a', 'b', and 'c'.You are asked to apply the following algorithm on the string any number of times :
//
// Pick a non - empty prefix from the string s where all the characters in the prefix are equal.
// Pick a non - empty suffix from the string s where all the characters in this suffix are equal.
// The prefix and the suffix should not intersect at any index.
// The characters from the prefix and suffix must be the same.
// Delete both the prefix and the suffix.
// 
// Return the minimum length of s after performing the above operation any number of times(possibly zero times).

using namespace std;
#include <string>

class Solution {
public:
    int minimumLength(string s)
    {
        while (s.length() > 0)
        {
            if (s.length() == 1)
            {
                return 1;
            }
            int lastIndex = s.length() - 1;

            if (s[0] == s[lastIndex])
            {
                if (s.length() == 2)
                {
                    return 0;
                }

                int prefixLength = 1;
                for (int i = 1; i < s.length(); i++)
                {
                    if (s[i] == s[0]) {
                        prefixLength++;
                    }
                    else
                    {
                        break;
                    }
                }
                int suffixLength = 1;
                for (int i = lastIndex - 1; i > 0; i--)
                {
                    if (s[i] == s[lastIndex]) {
                        suffixLength++;
                    }
                    else
                    {
                        break;
                    }
                }
                s.erase(lastIndex - suffixLength + 1, suffixLength);
                s.erase(0, prefixLength);

            }
            else {
                break;
            }
        }
        return s.length();
    }
};