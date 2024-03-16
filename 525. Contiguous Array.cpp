//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        int sum = 0;
        int subArray_length = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0) {
                subArray_length = i + 1;
            }
            else if (mp.find(sum) != mp.end()) {
                subArray_length = std::max(subArray_length, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        return subArray_length;
    }
};