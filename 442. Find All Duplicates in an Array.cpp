//Given an integer array nums of length n where all the integers of nums are in the range[1, n] 
//and each integer appears once or twice, return an array of all the integers that appears twice.
//
//You must write an algorithm that runs in O(n) time and uses only constant extra space.

#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums)
    {
        std::vector<int> twiceNums;

        for (int i = 0; i < nums.size(); i++) 
        {
            int num = abs(nums[i]);
            int index = num - 1;
            if (nums[index] < 0) 
                twiceNums.push_back(num);
            
            nums[index] *= -1;
        }

        return twiceNums;
    }
};