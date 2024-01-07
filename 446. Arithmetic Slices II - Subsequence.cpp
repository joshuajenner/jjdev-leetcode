#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array nums, return the number of all the arithmetic subsequences of nums.

// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
// For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
// A subsequence of an array is a sequence that can be formed by removing some elements(possibly none) of the array.

// For example, [2, 5, 10] is a subsequence of[1, 2, 1, 2, 4, 1, 5, 10].
// The test cases are generated so that the answer fits in 32 - bit integer.

int numberOfArithmeticSlices(vector<int>& nums);

int numberOfArithmeticSlices(vector<int>& nums)
{
    int n = nums.size();
    int totalCount = 0;

    // dp[i][d] represents the number of arithmetic subsequences ending at index i with common difference d
    vector<unordered_map<long long, int>> dp(n);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long diff = (long long)nums[i] - nums[j];

            // Check for possible integer overflow
            if (diff < INT_MIN || diff > INT_MAX)
                continue;

            int count = dp[j].count(diff) ? dp[j][diff] : 0;

            // Add the count to the total and update dp[i][diff]
            totalCount += count;
            dp[i][diff] += count + 1;
        }
    }

    return totalCount;
}