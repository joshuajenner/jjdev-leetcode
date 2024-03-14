//Given a binary array nums and an integer goal, 
//return the number of non - empty subarrays with a sum goal.
//
//A subarray is a contiguous part of the array.


#include <vector>

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal)
    {
        int size = nums.size();
        int goalSubVectors = 0;

        for (int subSize = 1; subSize <= size; subSize++)
        {
            for (int endIndex = subSize; endIndex < size; endIndex += subSize)
            {
                int sum = 0;
                std::cout << "SubSize = " << subSize << " Starting @ " << endIndex - subSize << " Ending @ " << endIndex << std::endl;
                for (int i = endIndex - subSize; i < endIndex; i++) {
                    sum += nums[i];
                }
                if (sum == goal) {
                    goalSubVectors++;
                }
            }
        }

        return goalSubVectors;
    }
};