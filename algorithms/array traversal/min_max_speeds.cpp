// Given 2 vectors of integers,
// where eachi nteger is a speed,
// and a boolean telling if we want the max or mins,
// compute the sum of max or min possible speeds,
// where the speed is a max of a pair of ints from the 2 vectors
// O(nlogn) time, constant space.


#include <vector>

using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) 
{
  
	std::sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
	std::sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
	int res = 0;
	size_t n = redShirtSpeeds.size();
	int left = 0;
	int right = n - 1;
	
	if (fastest)
	{
		while (left < n) 
		{
			res += std::max(redShirtSpeeds[left], blueShirtSpeeds[right]);
			++left;
			--right;
		}
	} else {
		right = 0;
		while (left < n) 
		{
			res += std::max(redShirtSpeeds[left], blueShirtSpeeds[right]);
			++left;
			++right;
		}
	}
	
  return res;
}