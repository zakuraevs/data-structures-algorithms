// Given an amount and denominations
// find the total ways to make that amount
// O(coins * amount) time, O(amount) space

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        if(amount == 0) return 1;
        
        // This vector tracks how many ways there are to make
        // Change for the given amount (index)
        // amount+1 since we take amount 0 into account too
        vector<int> num_of_ways(amount+1, 0);
        
        // 1 way to make change for 0
        num_of_ways[0] = 1;
        
        // We look at all the possible coins
        for(int coin : coins) {
            // We look at all possible amounts
            for(int i = 1; i <= amount; i++) {
                // If the current coin is not too large
                if(coin <= i) {
                    num_of_ways[i] += num_of_ways[i - coin];
                }
            }
        }
        return num_of_ways[amount];
    }
};