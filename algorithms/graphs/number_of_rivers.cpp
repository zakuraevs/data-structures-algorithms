// Given a matrix of rivers and land (1 and 0),
// find the number of rivers (connected 1s, diagonally or horizontally)
// O(wh) time and space(?), w = width, h = height.

#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> getNeighbors(const vector<vector<int>>& matrix, int x, int y) {
	
	//cout << "getting neighbors" << endl;
	
	size_t height = matrix.size();
	size_t width = matrix[0].size();
	
	//cout << "height: " << height << " widht: " << width << endl;
	
	vector<pair<int, int>> neighbors;
	
	// Checking North
	if (y - 1 > -1) {
		//cout << "getting North" << endl;
		neighbors.push_back(make_pair(x, y-1));
	}
	// Checking East
	if (x + 1 < width) {
		//cout << "getting East" << endl;
		neighbors.push_back(make_pair(x+1, y));
	}
	// Checking South
	if (y + 1 < height) {
		//cout << "getting South" << endl;
		neighbors.push_back(make_pair(x, y+1));
	}
	// Checking West
	if (x - 1 > -1) {
		//cout << "getting West" << endl;
		neighbors.push_back(make_pair(x-1, y));
	}
	//for (auto n : neighbors) {
		//cout << "(" << n.first << ", " << n.second << "), ";
	//}
	//cout << endl;
	
	return neighbors;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	
	//cout << "----------------------------" << endl;
  
	// Just sizes of all rivers
	vector<int> sizes;
	// pairs of coordinated x,y of unvisited locations
	queue<pair<int, int>> unvisited;

	size_t height = matrix.size();
	if (height == 0) return {};
	size_t width = matrix[0].size();
	
	//cout << "getting sizes in a " << height << " by " << width << " matrix"  << endl;
	
	unvisited.push(make_pair(0, 0));
	
	while (!unvisited.empty()) {
		
		//cout << "running an outer loop iteration" << endl;
		
		pair<int, int> current_address = unvisited.front();
		int current_x = current_address.first;
		int current_y = current_address.second;
		int current_location = matrix[current_y][current_x];
		unvisited.pop();
		
		matrix[current_y][current_x] = 2;
		
		if (current_location == 1) {
			// We found a part of a river!
			queue<pair<int, int>> river_parts;
			river_parts.push(make_pair(current_x, current_y));
			int river_size = 0;
			
			while (!river_parts.empty()) {
				//cout << "running an inner loop iteration" << endl;
				pair<int, int> current_river_address = river_parts.front();
				int current_river_x = current_river_address.first;
				int current_river_y = current_river_address.second;
				river_size++;
				//matrix[current_river_y][current_river_x] = 2;
				river_parts.pop();
				
				vector<pair<int, int>> river_neighbors = getNeighbors(matrix, current_river_x, current_river_y);
				for (auto coords : river_neighbors) {
					//cout << "running neighbor for loop iteration" << endl;
					//cout << " coords to be checked:" << coords.first << ", "<< coords.second << endl;
					if (matrix[coords.second][coords.first] == 1) {
						//cout << "pushing a river neighbor" << endl;
						matrix[coords.second][coords.first] = 2;
						river_parts.push(coords);
					} else if (matrix[coords.second][coords.first] == 0){
						unvisited.push(coords);
					}
				}
			}
			sizes.push_back(river_size);
		}
		
		vector<pair<int, int>> neighbors = getNeighbors(matrix, current_x, current_y);
		for (auto coords : neighbors) {
				if (matrix[coords.second][coords.first] != 2) {
					unvisited.push(coords);
				}
		}

	}

  return sizes;
}
