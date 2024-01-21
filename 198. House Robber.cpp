// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint
// stopping you from robbing each of them is that adjacent houses have
// security systems connected and it will automatically contact the police
// if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        int previous = 0;
        int current = 0;

        for (int index = 0; index < size; index++)
        {
            int temp = max(previous + nums[index], current);
            previous = current;
            current = temp;
        }

        return current;
    }
};