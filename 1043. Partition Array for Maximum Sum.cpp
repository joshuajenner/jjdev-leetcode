// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning,
// each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int solve(vector<int> &arr, int k, int ind)
    {
        int n = arr.size(), mx = 0, ans = 0;
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        for (int i = ind; i < min(ind + k, n); i++)
        {
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1) * mx + solve(arr, k, i + 1));
        }
        dp[ind] = ans;
        return ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        dp.resize(arr.size(), -1);
        return solve(arr, k, 0);
    }
};