// Given an integer array nums that does not contain any zeros,
// find the largest positive integer k such that -k also exists in the array.

// Return the positive integer k. If there is no such integer, return -1.

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int findMaxK(std::vector<int> &nums)
    {
        int maxK = -1;
        std::unordered_map<int, bool> numsMap;

        for (int num : nums)
        {
            int key = abs(num);
            if (numsMap.count(key))
            {
                if (numsMap[key] == true && num < 0 || numsMap[key] == false && num > 0) 
                {
                    maxK = std::max(maxK, key);
                }
            }
            else
            {
                numsMap[key] = (num > 0) ? true : false;
            }
        }

        return maxK;
    }
};