// Given 2 vectors of integers,
// determine if all values of one are strictly
// greater than of the other
// O(nlogn) time, constant space.


#include <vector>

using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) 
{
  
	std::sort(redShirtHeights.begin(), redShirtHeights.end());
	std::sort(blueShirtHeights.begin(), blueShirtHeights.end());
	
	size_t n = redShirtHeights.size();
	
	bool all_red_taller = true;
	bool all_red_shorter = true;
	
	for (int i = 0; i < n; ++i)
	{
		if (redShirtHeights[i] <= blueShirtHeights[i]) 
		{
			all_red_taller = false;
		} 
		if (redShirtHeights[i] >= blueShirtHeights[i]) {
			all_red_shorter = false;
		}
		if (!all_red_taller && !all_red_shorter)
		{
			return false;
		}
	}
	
  return all_red_taller || all_red_shorter;
}