// iterative version 1
int coinChange(std::vector<int>& coins, int amount) {
        
    if(amount == 0) return 0;
        
    int n = coins.size();
    int over = amount + 1;
    std::vector<int> minimums(over, over);
    minimums[0] = 0;
        
    for(int am = 1; am <= amount; ++am ){    
        std::vector<int> mins_with_denoms(n);
        for(int den = 0; den < n; ++den){
            if(coins[den] <= am) {
                mins_with_denoms[den] = min(minimums[am], minimums[am - coins[den]] + 1);
            } else {
                mins_with_denoms[den] = over;
            }
        }
        minimums[am] = *std::min_element(mins_with_denoms.begin(), mins_with_denoms.end()); 
    }
        
    if(minimums[amount] > amount) return -1;
    return minimums[amount];
        
}

// iterative version 2
// O(coins.size() * amount) time
// O(amount) space
int coinChange(std::vector<int>& coins, int amount) {
        
    if(amount == 0) return 0;
        
    int n = coins.size();
    int over = amount + 1;
    std::vector<int> minimums(over);
    minimums[0] = 0;
        
    sort(begin(coins), end(coins));
        
    for(int am = 1; am <= amount; ++am ){
        minimums[am] = over;
        for(int den = 0; den < n; ++den){
            if(coins[den] > am)
                break;
            else    
                minimums[am] = min(minimums[am], minimums[am - coins[den]] + 1);
        }
    }
        
    return minimums[amount] > amount ? -1 : minimums[amount];
        
}

// recursive
// O(coins.size() * amount) time since worst case there are amount levels of the tree
// and each subproblem does coins.size() work
// O(amount) space - max size of cal lstack
int coinChange(std::vector<int>& coins, int amount) {
    if (amount < 1) return 0;
    // count stores optimal (min) numbers of coins for different amounts
    // i.e. memoization. Index 0 is unused for syntactic convenience later.
    std::vector<int> count(amount + 1);
    // calling the recursive function
    return coinChangeInner(coins, amount, count);
}

int coinChangeInner(std::vector<int>& coins, int remaining, std::vector<int>& count) {
        
    // if the remaining amount is negative, there is no solution
    if(remaining < 0) return -1;
    // if the amount is 0, 0 coins are needed
    if(remaining == 0) return 0;
    // if we already know the min at this count, we return it
    // i.e. prunin repeating branches of the tree
    if (count[remaining] != 0) return count[remaining];
        
    // otherwise:
        
    // initially we set the min value of current amount high
    int min = INT_MAX;
        
    // looping over all the coins
    for(int coin : coins) {
            
        // we see what's the optimal value for amount - current coin
        int res = coinChangeInner(coins, remaining - coin, count);
            
        // if the result is feasible and better than what we already have
        // we use it and the current coin
        if (res >= 0 && res < min)
        min = 1 + res;
    }
        
    // we memoize the count for current amount
    count[remaining] = (min == INT_MAX) ? -1 : min;
    return count[remaining];
}