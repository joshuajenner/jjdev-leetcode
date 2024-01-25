//Given two strings text1 and text2, return the length of their longest common subsequence.
//If there is no common subsequence, return 0.
//
//A subsequence of a string is a new string generated from the original string with some characters(can be none) 
// deleted without changing the relative order of the remaining characters.
//
//For example, "ace" is a subsequence of "abcde".
//A common subsequence of two strings is a subsequence that is common to both strings.


//Constraints:
//
//1 <= text1.length, text2.length <= 1000
//text1 and text2 consist of only lowercase English characters.

using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        vector<int> dp(size2 + 1, 0);
        vector<int> prev(size2 + 1, 0);

        for (int index1 = 1; index1 <= size1; index1++) {
            for (int index2 = 1; index2 <= size2; index2++) {
                if (text1[index1 - 1] == text2[index2 - 1]) {
                    dp[index2] = 1 + prev[index2 - 1];
                }
                else {
                    dp[index2] = max(prev[index2], dp[index2 - 1]);
                }
            }
            prev = dp;
        }

        return dp[size2];
    }
};