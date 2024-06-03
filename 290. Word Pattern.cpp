// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between
// a letter in pattern and a non-empty word in s.

#include <string>
#include <unordered_map>
#include <vector>


bool wordPattern(std::string pattern, std::string s)
{
    std::vector<std::string> words = splitString(s);
    std::unordered_map<char, std::string> patternMap;

    if (pattern.size() != words.size())
    {
        return false;
    }

    for (int i = 0; i < pattern.size(); i++)
    {
        std::unordered_map<char, std::string>::iterator it;
        for (it = patternMap.begin(); it != patternMap.end(); it++)
        {
            if (it->first == pattern[i] && it->second != words[i])
            {
                return false;
            }
            if (it->first != pattern[i] && it->second == words[i])
            {
                return false;
            }
        }
        patternMap[pattern[i]] = words[i];
    }

    return true;
}

std::vector<std::string> splitString(std::string s)
{
    std::vector<std::string> value;
    int start = 0;
    int end = 0;

    while (end <= s.size())
    {
        if (s[end] == ' ' || end == s.size())
        {
            value.push_back(s.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }

    return value;
}