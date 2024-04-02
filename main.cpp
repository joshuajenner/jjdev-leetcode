#include <iostream>
#include <string>
using namespace std;

#include <unordered_map>
bool isIsomorphic(std::string s, std::string t)
{
    std::unordered_map<char, char> sMap;
    std::unordered_map<char, char> tMap;

    for (int i = 0; i < s.size(); i++)
    {
        if (sMap.count(s[i]))
        {
            if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])
            {
                return false;
            }
        }
        else
        {
            sMap[s[i]] = t[i];
            tMap[t[i]] = s[i];
        }
    }

    return true;
}

int main()
{
    isIsomorphic("badc", "baba");
    cout << "\n";

    std::cin.get();
};

