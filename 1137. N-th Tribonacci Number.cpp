// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

class Solution {
public:
    int tribonacci(int n) 
    {
        if (n == 0) {
            return 0;
        }

        int sum = 1;
        int prev1 = 1;
        int prev2 = 0;
        int prev3 = 0;

        for (int i = 1; i < n; i++) 
        {
            sum = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = sum;

        }

        return sum;
    }
};