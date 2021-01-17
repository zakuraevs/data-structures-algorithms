// Given a matrix of m rows and n cols,
// Traverse it in a clockwise spiral, adding elements to a result vector,
// then return that vector
// O(mn) time and aspace

vector<int> spiralTraverse(vector<vector<int>> array) {
	
	std::vector<int> res;
	int rows = array.size();
	// edge cases check
	//if(rows == 1) throw std::invalid_argument("bad input array..."); 
	int cols = array[0].size();
	
	int left = 0;
	int right = cols - 1;
	int up = 0;
	int down = rows - 1;
	
	//int row = 0;
	//int col = 0;
	
	// check if condition is correct later
	while(left <= right && up <= down) {
		cout << "------------------" << endl;

		cout << "moving right!" << endl;
		for(int col = left; col <= right; col++) {
			res.push_back(array[up][col]);
		}
		
		cout << "moving down!" << endl;
		for(int row = up + 1; row <= down; row++) {
			res.push_back(array[row][right]);
		}
		
		cout << "moving left!" << endl;
		for(int col = right - 1; col >= left; col--) {
			if(up == down)
				break;
			res.push_back(array[down][col]);
		}
		
		cout << "moving up!" << endl;
		for(int row = down - 1; row > up; row--) {
			if(left == right)
				break;
			res.push_back(array[row][left]);
		}
		
		left++;
		right--;
		up++;
		down--;
		
		cout << "up " << up << endl;
		cout << "down " << down << endl;
		cout << "left " << left << endl;
		cout << "right " << right << endl;
	}

  return res;
}
