#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Given a vector of strings that has been sorted, but rotated
// e.g. {c, d, a, b}
// the algorithm finds the "rotation, point", i.e. the
// index of the smallest element of the vector, 2 in this case

// O(s*logn) time where n is the size of the vector and s is the 
// size of the longest string
// O(1) space

size_t findRotationPoint(const vector<string>& words)
{

    int n = words.size();
    
    if(n < 2) return 0;
    
    int left = 0;
    int right = n - 1;
    int mid = left + (right - left) / 2;
    
    if(words[left] <= words[right]) return 0;
    
    // not sure about the while condition 
    while(left < right) 
    {
        
        // If the word at index 0 is greater than at mid
        // then we know for sure that the rotation point
        // is in the interval (left, mid]
        // elemetn at 0 can't be the point since it's bigger
        // than the smallest element
        // but element at mid can be, since it could be 
        // the smalelst of all
        if(words[left] > words[mid]) 
        {
            left = left + 1;
            right = mid;
        }
        // Otherwise we know for sure that the
        // rotation point is in the interval
        // (mid, right]
        // i.e. words[mid] > words [right]
        // and element at mid cannot be the smallest
        else
            left = mid + 1;
        mid = left + (right - left) / 2;
    }
    
    return mid;
}
