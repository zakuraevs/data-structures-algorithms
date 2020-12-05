// given a vector of integers, freturn a vector of integers
// where each element is the product of all elements in the 
// original excepl at the current index
// without using division

#include <vector>

using namespace std;

// O(n) time and space
vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{

    int n = intVector.size();
    
    if(n < 2) {
        throw invalid_argument("not enough elements");
    }
    
    vector<int> res(n);
    
    int prod_left = 1;
    int prod_right = 1;
    
    for(int lo = 0; lo < n; ++lo) {
        res[lo] = prod_left;
        prod_left *= intVector[lo];
    }
    
    for(int hi = n - 1; hi >= 0; --hi){
        res[hi] *= prod_right;
        prod_right *= intVector[hi];
    }

    return res;
}