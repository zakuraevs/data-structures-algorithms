// Given a vector of integers, and a target integer,
// find all quadruplets of values that sum up to target
// O(n^3) time, O(n^2) space

#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  
	vector<vector<int>> result;
	unordered_map<int, vector<vector<int>>> two_sum_to_indices;
	vector<int> pair_sums;
	size_t n = array.size();
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			int sum = array[i] + array[j];
			two_sum_to_indices[sum].push_back({i, j});
			pair_sums.push_back(sum);
		}
	}
	
	size_t pair_count = pair_sums.size();
	
	for (int i = 0; i < pair_count; ++i) {
		int pair_sum = pair_sums[i];
		int remainder = targetSum - pair_sum;
		vector<vector<int>> pair_sum_candidates = two_sum_to_indices[pair_sum];
		vector<vector<int>> remainder_sum_candidates = two_sum_to_indices[remainder];
		if (remainder_sum_candidates.size() < 1)
			continue;
		
		for (vector<int> pair_sum_candidate : pair_sum_candidates) {
			for (vector<int> remainder_sum_candidate : remainder_sum_candidates) {
				if (pair_sum_candidate[0] != remainder_sum_candidate[0]
					 	&& pair_sum_candidate[0] != remainder_sum_candidate[1]
					 	&& pair_sum_candidate[1] != remainder_sum_candidate[0]
					 	&& pair_sum_candidate[1] != remainder_sum_candidate[1]
					 ) {
					vector<int> values = {array[pair_sum_candidate[0]], array[pair_sum_candidate[1]], array[remainder_sum_candidate[0]], array[remainder_sum_candidate[1]]};
					sort(values.begin(), values.end());
					if (find(result.begin(), result.end(), values) == result.end())
						result.push_back(values);
				}
			}
		}
	}
  return result;
}
