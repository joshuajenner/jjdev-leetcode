#include <vector>
using namespace std;

// You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
// Return the wealth that the richest customer has.

// A customer's wealth is the amount of money they have in all their bank accounts. 
// The richest customer is the customer that has the maximum wealth.

int maximumWealth(vector<vector<int>>& accounts);

int maximumWealth(vector<vector<int>>& accounts)
{
	int maxSum = 0;

	for (vector<int> account: accounts)
	{
		int currentSum = 0;
		for (int balance: account)
		{
			currentSum += balance;
		}
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
	}

	return maxSum;
}