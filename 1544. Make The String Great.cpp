//Given a string s of lower and upper case English letters.
//
//A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
//
//0 <= i <= s.length - 2
//s[i] is a lower - case letter and s[i + 1] is the same letter but in upper - case or vice - versa.
//To make the string good, you can choose two adjacent characters that make the string bad and remove them.
//You can keep doing this until the string becomes good.
//
//Return the string after making it good.The answer is guaranteed to be unique under the given constraints.
//
//Notice that an empty string is also good.

#include <string>
#include <cctype>
#include <iostream>

std::string makeGood(std::string s) 
{
    int loop = 0;
    const int maxLoop = 50;

    while (loop < maxLoop)
    {
        bool didErase = false;
        for (int i = 0; i <= s.size() - 2; i++) 
        {
            if (
                (std::tolower(s[i]) == std::tolower(s[i + 1])) &&
                ((std::islower(s[i]) && std::isupper(s[i + 1])) || (std::isupper(s[i]) && std::islower(s[i + 1])))
               )
            {
                s.erase(i, 2);
                didErase = true;
            }
            if (i >= s.size()) 
                break;
        }
        if (!didErase) 
            break;
        loop++;
    }

    return s;
}


int main() 
{
    std::cout << makeGood("abBAcC");
}