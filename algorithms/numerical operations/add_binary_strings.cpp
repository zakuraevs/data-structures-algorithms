// Given two binary strings,
// compute their sum
// O(max(n,m)) time and space, where n is the length of string a and 
// m is the length of string b

#inlcude <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        size_t n = a.size();
        size_t m = b.size();
        int carry_over = false;
        std::string result = "";
        
        int ia = n - 1;
        int ib = m - 1;
        
        while (ia > -1 && ib > -1) {
            char bit_a = a[ia];
            char bit_b = b[ib];
            
            if (bit_a == '1' && bit_b == '1') {
                if (carry_over) {
                    result.push_back('1');
                } else {
                    result.push_back('0');
                    carry_over = true;
                }
            } else if (bit_a == '0' && bit_b == '1' || bit_a == '1' && bit_b == '0') {
                if (carry_over) {
                    result.push_back('0');
                } else {
                    result.push_back('1');
                }
            } else {
                if (carry_over) {
                    result.push_back('1');
                    carry_over = false;
                } else {
                    result.push_back('0');
                }
            }
            --ia;
            --ib;
        }
        
        while (ia > -1) {
            // not optimal
            if (carry_over) {
                if (a[ia] == '1') {
                    result.push_back('0');
                } else {
                    result.push_back('1');
                    carry_over = false;
                }
            } else {
                result.push_back(a[ia]);
            }
            --ia;
        }
        
        
        while (ib > -1) {
            if (carry_over) {
                if (b[ib] == '1') {
                    result.push_back('0');
                } else {
                    result.push_back('1');
                    carry_over = false;
                }
            } else {
                result.push_back(b[ib]);
            }
            --ib;
        }
        
        if (carry_over) {
            result.push_back('1');
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;

    }
};