#include <string>
#include <vector>
using namespace std;

// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).

int arraySign(vector<int> &nums);

int arraySign(vector<int> &nums)
{
    double product = 1;
    for (auto iter = nums.begin(); iter < nums.end(); iter++)
    {
        product *= *iter;
    }
    if (product > 0)
    {
        return 1;
    }
    else if (product < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}