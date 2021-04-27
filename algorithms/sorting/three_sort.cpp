// Given an vector of integers where only 1-3 distinct integers appear,
// and another vector with these 3 elements ordered,
// sort the firt vector in place.
// O(n) time, O(1) space


#include <vector>
#include <unordered_map>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) 
{
  
	
	int x = order[0];
	int y = order[1];
	int z = order[2];
	size_t n = array.size();
	unordered_map<int, int> value_to_count;
	
	value_to_count[x] = 0;
	value_to_count[y] = 0;
	value_to_count[z] = 0;
	
	for (int i = 0; i < n; i++) 
	{
		if (array[i] == x) value_to_count[x]++;
		else if (array[i] == y) value_to_count[y]++;
		else value_to_count[z]++;
	}
	
	int i = 0;

	while (value_to_count[x] > 0)
	{
		array[i] = x;
		value_to_count[x]--;
		i++;
	}
	
	while (value_to_count[y] > 0)
	{
		array[i] = y;
		value_to_count[y]--;
		i++;
	}
	
	while (value_to_count[z] > 0)
	{
		array[i] = z;
		value_to_count[z]--;
		i++;
	}
	
  return array;
}
