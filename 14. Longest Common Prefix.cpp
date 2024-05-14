// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string commonPrefix = "";

    std::sort(strs.begin(), strs.end());
    std::string firstStr = strs[0];
    std::string lastStr = strs[strs.size() - 1];

    for (int i = 0; i < std::min(firstStr.size(), lastStr.size()); i++) 
    {
        if (firstStr[i] != lastStr[i]) 
        {
            // Faster than break; 0ms vs 3ms
            return commonPrefix;
        }

        commonPrefix += firstStr[i];
    }

    return commonPrefix;
}