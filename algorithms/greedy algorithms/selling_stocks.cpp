
// given an array of stock prices, and knowing we are allowed
// to buy and sell once, where buy time > sell time,
// what is the largegst profit we can have, inc. negatice.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMaxProfit(const vector<int>& stockPrices)
{
    // calculate the max profit
    
    if(stockPrices.size() < 2) {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }
    
    int n = stockPrices.size();
    int smallest = stockPrices[0];
    int profit = INT_MIN;
    
    
    for(int i = 1; i < n; ++i) {
        // replace these two if we don't want negative
        if((stockPrices[i] - smallest) > profit )
            profit = stockPrices[i] - smallest;
        if(stockPrices[i] < smallest)
            smallest = stockPrices[i];
    }
    
    return profit;
}
