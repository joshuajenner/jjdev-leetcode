#include <vector>
#include <algorithm>
using namespace std;

// You are given an integer array prices representing the prices of various chocolates in a store.
// You are also given a single integer money, which represents your initial amount of money.

// You must buy exactly two chocolates in such a way that you still have some non - negative leftover money.
// You would like to minimize the sum of the prices of the two chocolates you buy.

// Return the amount of money you will have leftover after buying the two chocolates.
// If there is no way for you to buy two chocolates without ending up in debt, return money.
// Note that the leftover must be non - negative.

int buyChoco(vector<int>& prices, int money);

int buyChoco(vector<int>& prices, int money)
{
	sort(prices, prices.size());

	int lowestLeftover = -1;

	for (int index = 0; index < prices.size() - 1; index++) 
	{
		int checkLeftover = money - (prices[index] + prices[index + 1]);

		if (lowestLeftover == -1 && checkLeftover > 0) 
		{
			lowestLeftover = checkLeftover;
		}
		else if (checkLeftover < lowestLeftover && checkLeftover > 0)
		{
			lowestLeftover = checkLeftover;
		}
		else if (checkLeftover == 0) 
		{
			lowestLeftover = checkLeftover;
			break;
		}
	}

	if (lowestLeftover == -1) 
	{
		return money;
	}
	else 
	{
		return lowestLeftover;
	}
}