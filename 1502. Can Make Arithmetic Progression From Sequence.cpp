#include <vector>
#include <algorithm>
using namespace std;

// A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

bool canMakeArithmeticProgression(vector<int> &arr);

bool canMakeArithmeticProgression(vector<int> &arr)
{
    if (arr.size() == 2)
    {
        return true;
    }

    sort(arr.begin(), arr.end());

    for (int index = 2; index < arr.size(); index++)
    {
        if ((arr[index] - arr[index - 1]) != (arr[index - 1] - arr[index - 2]))
        {
            return false;
        }
    }
    return true;
}