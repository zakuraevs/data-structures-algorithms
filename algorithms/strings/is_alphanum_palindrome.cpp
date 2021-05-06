// Given a string,
// determine if it is a palindrome,
// only considering alphanumeric characters
// O(n) time, constant space.

#include <string>

bool isPalindrome(string s) {
        
        size_t n = s.size();
        
        int left = 0;
        int right = n - 1;
        
        while (left < right)
        {
            // ignoring non-alphanumeric characters
            while (left < n && !isalnum(s[left]))
            {
                ++left;
            }
            while (right > -1 && !isalnum(s[right]))
            {
                --right;
            }
            // if only non-alphanum were left in the string, we're done
            if (left >= right)
            {
                break;
            }
            // if alphanum chars at left and right are not the same,
            // s is not a palyndrome
            if (std::tolower(s[left]) != std::tolower(s[right]))
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }