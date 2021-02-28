// Given an adjacency list representing a directed graph,
// check if there are any cycles in the graph
// O(n + e) time, O(n*e) or O(n) space

#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

bool dfs(const vector<vector<int>>& edges, const int& current_node, 
				 vector<bool>& visited, vector<bool>& call_stack) {
	
	vector<int> children = edges[current_node];
	
	visited[current_node] = true;
	call_stack[current_node] = true;
	
	// 1. check for back edges	
	for(int child : children) {
		if (call_stack[child])
			return true;
	}
		
	// 2. dfs children
	for (int child : children) {
		if (!visited[child]) {
			bool res = dfs(edges, child, visited, call_stack);
			if (res)
				return true;
		}
	}
	
	// 3. remove itself from call stack
	call_stack[current_node] = false;
	
	return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  
	size_t num_of_nodes = edges.size();
	vector<bool> visited(num_of_nodes, false);
	vector<bool> call_stack(num_of_nodes, false);
	
	if (!visited[node]) {
		int search_res = dfs(edges, node, visited, call_stack);
		if (search_res)
			return true;
	}
	
  return false;
}