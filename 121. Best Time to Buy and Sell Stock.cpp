// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and 
// choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.

#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) 
{
    int buyPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) 
    {
        if (buyPrice > prices[i])
        {
            buyPrice = prices[i];
        }

        profit = std::max(profit, prices[i] - buyPrice);
    }

    return profit;        
}