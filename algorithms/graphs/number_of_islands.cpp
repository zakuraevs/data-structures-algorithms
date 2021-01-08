// Given an mxn grid, where 1 is land and 0 is water, return the number of islands in the grid
// An island is formed by 1s connected vertically and horizontally

#include <unordered_set>
#include <stack>
#include <vector>

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
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