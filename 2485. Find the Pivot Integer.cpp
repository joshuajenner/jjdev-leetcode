//Given a positive integer n, find the pivot integer x such that :
//
//The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
//Return the pivot integer x. If no such integer exists, return -1. 
//It is guaranteed that there will be at most one pivot index for the given input.

class Solution
{
public:
    int pivotInteger(int n)
    {
        int checkX = n;

        while (checkX >= 1)
        {
            int leftSum = sumAll(checkX);
            int rightSum = sumAll(n) - sumAll(checkX - 1);

            if (leftSum == rightSum)
            {
                return checkX;
            }
            else if (leftSum > rightSum)
            {
                checkX--;
            }
            else if (leftSum < rightSum)
            {
                return -1;
            }
        }
        return -1;
    }

    int sumAll(int n)
    {
        return n * (n + 1) / 2;
    }
};