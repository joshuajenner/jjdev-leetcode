#include <iostream>
using namespace std;

// Given two non-negative integers low and high. 
// Return the count of odd numbers between low and high (inclusive).

int countOdds(int low, int high);

int countOdds(int low, int high)
{
	int odds = 0;

	for (int counter = low; counter <= high; counter++)
	{
		if ((counter % 2) != 0)
		{
			odds += 1;
			counter += 1;
		}
	}

	return odds;
}