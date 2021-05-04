// Given a vector of query durations,
// where queries can be completed in arbitrary order 
// and a query's waiting time is the amount of time
// it has to wait before executing - sum of times of all 
// predecessor queries
// find the shortest time to execute all the queries
// O(nlong) time, O(n) space. 


#include <vector>

using namespace std;

int minimumWaitingTime(vector<int> queries) {

	std::sort(queries.begin(), queries.end());
	
	int running = 0;
	int res = 0;
	size_t n = queries.size();
	
	for (int i = 1; i < n; ++i)
	{
		running += queries[i-1];
		res += running;
	}
	
  return res;
}