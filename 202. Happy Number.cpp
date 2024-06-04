// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), 
// or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

#include <string>

bool isHappy(int n) 
{
    int sum = n;
    int loopCheck = 4;

    while (sum != loopCheck) 
    {
        sum = squareSumDigits(sum);

        if (sum == 1)
        {
            return true;
        }
    }

    return false;
}

int squareSumDigits(int n) 
{
    int sum = 0;

    while(n != 0)
    {
        int num = n % 10;
        sum += num * num;
        n = n / 10;
    }

    return sum;
}