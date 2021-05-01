// Given a vector of coins repeating value allowed,
// compute the minimum amount of change that cannot be made
// with the given coins.
// O(nlogn) time, O(1) space

#include <vector>

int nonConstructibleChange(std::vector<int> coins) {
  
	// precomputing number of coins
	size_t n = coins.size();
	// this variable will track the minimum change we can make
	int min_possible = 0;
	// we sort he input array
	std::sort(coins.begin(), coins.end());
	
	// iterate over the sorted input
	for (int i = 0; i < n; ++i)
	{
		// current value
		int current_coin = coins[i];
		// if current_coin > min_possible + 1,
		// then there is no way we can make min_possible + 1.
		// we're either too low (using all coins so far),
		// or too high with the new value
		if (current_coin > min_possible + 1)
		{
			return min_possible + 1;
			// otherwise we can make anything we could before + the 
			// current amount
		} else {
			min_possible += current_coin;
		}
	}

	// by default return this
  return min_possible + 1;
}