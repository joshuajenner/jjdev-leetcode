//You are given an integer array nums and an integer k.
//
//The frequency of an element x is the number of times it occurs in an array.
//
//An array is called good if the frequency of each element in this array is less than or equal to k.
//
//Return the length of the longest good subarray of nums.
//
//A subarray is a contiguous non - empty sequence of elements within an array.

#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> numsMap;
        int numsSize = nums.size();
        int maxSubSize = 1;
        int currentSubSize = 0;

        for (int i = 0; i < numsSize; i++) 
        {
            for (int j = i; j < numsSize; j++)
            {
                numsMap[nums[j]]++;
                if (numsMap[nums[j]] > k)
                {
                    maxSubSize = currentSubSize > maxSubSize ? currentSubSize : maxSubSize;
                    numsMap.clear();
                    currentSubSize = 0;
                    break;
                }
                currentSubSize++;
            }
            maxSubSize = currentSubSize > maxSubSize ? currentSubSize : maxSubSize;
        }
        return currentSubSize > maxSubSize ? currentSubSize : maxSubSize;
    }
};