// Given an integer array nums and an integer k, return true if there are two distinct 
// indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

#include <vector>
#include <set>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) 
{
    std::set<int> visitedNums;

    for (int i = 0; i < nums.size(); i++) 
    {
        if (visitedNums.count(nums[i])) 
        {
            return true;
        }

        visitedNums.insert(nums[i]);

        if (visitedNums.size() > k) 
        {
            visitedNums.erase(nums[i - k]);
        }
    }

    return false;
}