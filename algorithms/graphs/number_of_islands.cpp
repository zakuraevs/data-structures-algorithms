// Given an mxn grid, where 1 is land and 0 is water, return the number of islands in the grid
// An island is formed by 1s connected vertically and horizontally

#include <unordered_set>
#include <stack>
#include <vector>

class Solution1 {
private:
    void recursiveDFS(vector<vector<char>>& grid, int row, int col) {
        
        // We mark the current location as visited
        grid[row][col] = '0';
        
        // We need to compute the dimenstions to check boundaries
        int rows = grid.size();
        int cols = grid[0].size();
        
        // We chek all the neighbors. If any of them is land, we DFS it recursively
        
        // Checking North
        if(row > 0 && grid[row-1][col] == '1')
            recursiveDFS(grid, row-1, col);
        
        // Checking East
        if(col < cols-1 && grid[row][col+1] == '1')
            recursiveDFS(grid, row, col+1);
            
        // Checking South
        if(row < rows-1 && grid[row+1][col] == '1')
            recursiveDFS(grid, row+1, col);
        
            // Checking north
        if(col > 0 && grid[row][col-1] == '1')
            recursiveDFS(grid, row, col-1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // We compute the dimensions of the grid
        int rows = grid.size();
        if(rows < 1) return 0;
        int cols = grid[0].size();
        if(cols < 1) return 0;

        // We're going to count how many islands there are
        int count = 0;
        
        // We're going to iterate over all of the rows x cols points in the grid
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                // If a point on the gird is land
                if(grid[row][col] == '1') {
                    // We've found a new island
                    count++;
                    
                    // Now we need to mark all the land connected to the initial point above
                    // with 0s
                    recursiveDFS(grid, row, col);
                    
                }
            }
        }
        
        return count;
    }
};

// A more verbose ans less efficient inital solution, that doesn't alter the initial grid

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // We're going to iterate over all the rows and all the columns of the grid
        int rows = grid.size();
        if(rows < 1) return 0;
        int cols = grid[0].size();
        if(cols < 1) return 0;
        
        // We're going to keep track of all the land that we visited
        std::unordered_set<std::pair<int, int>,  pair_hash> visited;
        
        // We're going to count how many islands there are
        int count = 0;
        
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                // If the current location is water, we keep looking,
                // If it's land, we are going to perform DFS and mark all the
                // land on this island as visited
                if(grid[row][col] == '1' && visited.find(std::make_pair(row, col)) == visited.end()) {
                    
                    //std::cout << "we found a new island!" << '\n';
                    // We're going to keep track of locations as x,y coordinates
                    std::pair<int, int> origin = std::make_pair(row, col);
                    std::stack< std::pair<int, int>> need_to_visit;
                    need_to_visit.push(origin);
                    count++;
                    
                    // While we have land to look at
                    while(!need_to_visit.empty()) {
                        std::pair<int, int> current = need_to_visit.top();
                        need_to_visit.pop();
                        
                        //std::cout << "inside the inner loop" << '\n';
                            
                        // We visit current
                        visited.insert(current);
                        
                        // We're going to look at all the neighbours of the current node
                        // Checking North
                        if(current.first > 0) {
                            if(grid[current.first-1][current.second] == '1' && visited.find(std::make_pair(current.first-1, current.second)) == visited.end()) {
                               need_to_visit.push(std::make_pair(current.first-1, current.second)); 
                               //std::cout << "adding North" << '\n';
                            }
                                
                        }
                        // Checking East
                        if(current.second < cols-1) {
                            if(grid[current.first][current.second+1] == '1' && visited.find(std::make_pair(current.first, current.second+1)) == visited.end()) {
                                need_to_visit.push(std::make_pair(current.first, current.second+1));
                                //std::cout << "adding East" << '\n';
                            }
                                
                        }
                        // Checking South
                        if(current.first < rows-1) {
                            if(grid[current.first+1][current.second] == '1'  && visited.find(std::make_pair(current.first+1, current.second)) == visited.end()) {
                                need_to_visit.push(std::make_pair(current.first+1, current.second));
                                //std::cout << "adding South" << '\n';
                            }
                                
                        }
                        // Checking West
                        if(current.second > 0) {
                            if(grid[current.first][current.second-1] == '1'  && visited.find(std::make_pair(current.first, current.second-1)) == visited.end()) {
                                need_to_visit.push(std::make_pair(current.first, current.second-1));
                                //std::cout << "adding West" << '\n';
                            }
                        }                        
                    }
                }
            }
        }
        
        return count;
    }
};