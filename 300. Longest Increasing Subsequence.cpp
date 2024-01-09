#include <vector>
using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

int lengthOfLIS(vector<int>& nums);

int lengthOfLIS(vector<int>& nums)
{
    vector<int> sequenceLengths(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (nums[i] > nums[j]) 
            {
                sequenceLengths[i] = max(sequenceLengths[i], sequenceLengths[j] + 1);
            }
        }
    }

    return *max_element(sequenceLengths.begin(), sequenceLengths.end());

}