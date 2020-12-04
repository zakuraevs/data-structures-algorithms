// sorts a vector with values within a range 0 until highestPossibleScore
// in linear time

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // suppose n is Max(unorderedScores.size(), highestPossibleScore)
    
    // O(n)
    int n = unorderedScores.size();
    
    // empty vector that will store the sorted scores
    vector<int> res;
    // a vector of size limited by highestPossibleScore
    // we know that all the scores are between 0 and 
    // highestPossibleScore
    vector<int> counts(highestPossibleScore, 0);
    
    // O(n)
    // go through unorderedScores and incrementing
    // counts of each element we encounter
    // at the corresponding index in counts
    for(int i = 0; i < n; ++i) {
        ++counts[unorderedScores[i]];
    }
    
    // since we want a decreasing sort, we go through counts
    // starting at the highest index (value) and pushing 
    // elements to res so long as their count is above 0
    for(int i = (highestPossibleScore-1); i >= 0; --i) {
        while(counts[i] > 0) {
            res.push_back(i);
            --counts[i];
        }
    }
    
    return res;
}