// Given a string, determine if it is a palindrome
// after deleting at most 1 character from it.
// O(n) time, constant space

#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(string s)
    {
        size_t n = s.size();
        
        int left = 0;
        int right = n - 1;
        
        while (left < right)
        {
            if (s[left] == s[right])
            {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        // when 2 chars are not the same
        // check if we try moving the left one:
        // same - proceed, attempt spend
        // if not, move back and try moving the right one similaryl
        
        size_t n = s.size();
        
        int left = 0;
        int right = n - 1;
        //bool one_different = false;
        
        while (left < right)
        {
            // base case, both are the same
            if (s[left] == s[right])
            {
                ++left;
                --right;
                continue;
            }

            // try checking left
            if (isPalindrome(s.substr(left, right-left))){
                return true;
            } else if (isPalindrome(s.substr(left+1, right-left))) {
                return true;
            } else {
                return false;
            }
            
        }
        
        // if we got this far, return true
        return true;
    }
};