// given a vector of integers, find the largest possible
// product of 3 integers in this vector. No multipication
// of a number with itself.

#include <vector>

using namespace std;

int highestProductOf3(const vector<int>& vectorOfInts)
{
    if(vectorOfInts.size() < 3) {
        throw invalid_argument("not enough inputs");
    }
    
    int n = vectorOfInts.size();
    
    int hi3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];
    int hi2 = vectorOfInts[0] * vectorOfInts[1];
    int hi = max(vectorOfInts[0], vectorOfInts[1]);
    int lo2 = vectorOfInts[0] * vectorOfInts[1];
    int lo = min(vectorOfInts[0], vectorOfInts[1]);

    
    for(int i = 2; i < n; ++i) {
        

        int  current = vectorOfInts[i];
        
        // check if we can get a new highest
        // product of 3
        hi3 = max(max(hi3, hi2 * current), lo2 * current);
        
        // then update values of the 4 other variables
        // for future use
        hi2 = max(max(hi2, hi * current), lo * current);
        
        lo2 = min(min(lo2, hi * current), lo * current);
        
        hi = max(hi, current);
        
        lo = min(hi, current);
    }
    
    return hi3;
}