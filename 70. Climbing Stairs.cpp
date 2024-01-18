// You are climbing a staircase.It takes n steps to reach the top.
//
// Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top?

class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 0;
        int b = 1;
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};
