// Given a string of bits,
// Count the number of non-empty substrings that have the same number of 0's and 1's, 
// and all the 0's and all the 1's in these substrings are grouped consecutively.
// A: O(n) time, O(n) space B: O(n) time, O(1) space

#include <vector>

class Solution {
public:
    int countBinarySubstringsA(string s) {
        int result = 0;
        size_t n = s.size();
        vector<int> groups;
        int i = 0;
        
        while (i < n) {
            char current_bit = s[i];
            int current_count = 0;
            while (s[i] == current_bit) {
                ++current_count;
                ++i;
            }
            groups.push_back(current_count);
        }
        size_t group_count = groups.size();
        
        for (int i = 1; i < group_count; ++i) {
            int prev_group = groups[i - 1];
            int current_group = groups[i];
            result += min(prev_group, current_group);
        }
        return result;
    }

    int countBinarySubstringsB(string s) {
        int result = 0;
        size_t n = s.size();
        int bit = 0;
        
        while (bit < n) {
            char current_val = s[bit];
            int same_bit_consecutive_count = 0;
            int different_bit_consecutive_count = 0;
            int i = bit;
            
            while (i < n && s[i] == current_val) {
                ++i;
                ++same_bit_consecutive_count;
            }
            
            while (i < n && s[i] != current_val && different_bit_consecutive_count < same_bit_consecutive_count) {
                ++i;
                ++different_bit_consecutive_count;
            }
            
            if (same_bit_consecutive_count == different_bit_consecutive_count) {
                result += same_bit_consecutive_count;
                bit += same_bit_consecutive_count;
            } else {
                ++bit;
            }
        }
        
        return result;
    }
};

    
