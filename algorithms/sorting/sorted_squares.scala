// Given a sorted array of integers, return a sorted array of squares of elements
// O(n) time and space. 

#include <vector>

std::vector<int> sortedSquaredArray(std::vector<int> array) {
	
	std::vector<int> res;
	size_t n = array.size();
	int nonnegative_index = n;
	int negative_index;
	
	// we find the first nonnegative index
	for (int i = 0; i < n; ++i) 
	{
		if (array[i] > -1)
		{
			nonnegative_index = i;
			break;
		}
	}
	negative_index = nonnegative_index - 1;
	
	// main loops
	while (negative_index > -1 && nonnegative_index < n)
	{
		int negative_sq = pow(array[negative_index], 2);
		int positive_sq =  pow(array[nonnegative_index], 2);
		
		if (negative_sq < positive_sq)
		{
			res.push_back(negative_sq);
			--negative_index;
		}
		else
		{
			res.push_back(positive_sq);
			++nonnegative_index;
		}
	}
										
	while (negative_index > -1)
	{
		res.push_back(pow(array[negative_index], 2));
		--negative_index;
	}
	
	while (nonnegative_index < n)
	{
		res.push_back(pow(array[nonnegative_index], 2));
		++nonnegative_index;
	}
	
  return res;
}