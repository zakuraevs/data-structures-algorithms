// Given a vector of integers and an integer targetSum,
// Return a vector of all integers in input vector, that sum up
// to the target.
// Both inner and outer vectors should be sorted.
// O(n^2) time, O(n) space

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  
	// Initialize map of value -> index in array
	std::unordered_map<int, int> values_indices;
	std::vector<std::vector<int>> res_vector;
	std::unordered_set<std::vector<int>, VectorHash> res_set;

	// Precompute size
	int n = array.size();
	
	// Run loop over array to fill the map
	// value -> index in array
	for(int i = 0; i < n; i++) {
		values_indices[array[i]] = i;
	}

	// Run a loop over the entire array O(n^2?)
	for(int i = 0; i < n; i++) {
		// Get a single value
		int current = array[i];
		// Compute what's the remainder that some other 2 numbers need to sum up to
		int three_remainder = targetSum - current;
		
		// We loop over all the n elements again
		// O(n)
		for(int j = 0; j < n; j++) {
			// Calculate remainder 
			int two_remainder = three_remainder - array[j];
			if(j != i && values_indices.find(two_remainder) != values_indices.end() && values_indices[two_remainder] != j && values_indices[two_remainder] != i) {
				std::vector<int> valid_triplet = {array[j], array[values_indices[two_remainder]], array[i]};
				std::sort(valid_triplet.begin(), valid_triplet.end());
				// Suboptimal
				//if(std::find(res.begin(), res.end(), valid_triplet) == res.end())
				res_set.insert(valid_triplet);
			}
		}
	}
	
	for(std::vector<int> i : res_set) {
		res_vector.push_back(i);
	}
	
	// Sort result
	// O(nlogn)
	std::sort(res_vector.begin(), res_vector.end());								
	
  return res_vector;
}
