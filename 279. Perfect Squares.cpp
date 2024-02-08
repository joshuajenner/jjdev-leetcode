//Given an integer n, return the least number of perfect square numbers that sum to n.
//
//A perfect square is an integer that is the square of an integer; in other words, 
//it is the product of some integer with itself.
//For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // dp vector to store answer from [1, n]
        vector<int> answers(n + 1);

        // Mark ans for perfect square numbers as 1
        for (int base = 1; base * base <= n; base++)
        {
            answers[base * base] = 1;
        }

        // find the answer from [1, n]
        for (int a = 1; a <= n; a++) {
            // if perfect square then skip
            if (answers[a] == 1) continue;

            // find the root of i
            // current ans is min of ans[j*j] + ans[i - j*j]
            int root = sqrt(a);
            int mn = INT_MAX;
            for (int b = 1; b <= root; b++) {
                mn = min(mn, answers[b * b] + answers[a - b * b]);
            }
            answers[a] = mn;
        }

        return answers[n];
    }
};