#include <string>
using namespace std;

// You are given a string s consisting only of the characters '0' and '1'. 
// In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal.
// For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.

int minOperations(string s);

int minOperations(string s)
{
    int length = s.size();
    int swapsNeeded = 0;

    for (int index = 0; index < length; index++)
    {
        if (index % 2 == 0 && s[index] == '1') 
        {
            swapsNeeded++;
        }
        if (index % 2 == 1 && s[index] == '0') 
        {
            swapsNeeded++;
        }
    }

    return min(swapsNeeded, (length - swapsNeeded));
}