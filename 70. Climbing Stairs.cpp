//You are climbing a staircase.It takes n steps to reach the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        int ways = 1;
        int numOf2s = 1;

        for (int index = n - 1; index >= 1; index--) {
            ways += combinations(numOf2s, index);
            numOf2s++;
        }

        return ways;
    }

    int combinations(int pick, int total) {
        return factorial(total) / factorial(total - pick) * factorial(pick);
    }

    int factorial(int num) {
        if (num <= 1) {
            return 1;
        }
        return num * factorial(num - 1);
    }
};