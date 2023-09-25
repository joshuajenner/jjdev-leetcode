#include <string>
using namespace std;

// Given a string s, return the string after replacing every uppercase letter 
// with the same lowercase letter.

string toLowerCase(string s);

string toLowerCase(string s)
{
    string returnString = "";
    for (int charIndex = 0; charIndex < s.length(); charIndex++)
    {
        int charASCII = int(s[charIndex]);
        if (charASCII >= 65 && charASCII <= 90)
        {
            charASCII += 32;
        }
        char lowercase = charASCII;
        returnString.push_back(lowercase);
    }
    return returnString;
}