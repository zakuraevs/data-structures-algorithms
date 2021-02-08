// Given two strings representing integers, with up to 5099 digits each,
// Return the sum of the two integers as a string
// O(max(n,m)) time, space, where n and m are lengths of input strings.

#include <string>

class Solution {
public:
    
    int charToInt(char c) {
        return (int)c - '0';
    }
    
    char intToChar(int i) {
        char res = i + '0';
        return res;
    }
    
    string addStrings(string num1, string num2) {
        
        int carry_over = 0;
        std::string res;
        int n1 = num1.size();
        int n2 = num2.size();
        int i1 = n1-1;
        int i2 = n2-1;
        
        while(i1 > -1 && i2 > -1) {
            int digit1 = charToInt(num1[i1]);
            int digit2 = charToInt(num2[i2]);

            int sum = digit1 + digit2 + carry_over;
            
            if(sum > 9) {
                carry_over = 1;
                sum -= 10;
            } else {
                carry_over = 0;
            }
                        
            char outcome = intToChar(sum);
                        
            res += outcome;
            
            i1--;
            i2--;
        }
        
        while(i1 > -1) {
            int digit1 = charToInt(num1[i1]);
            int sum = digit1 + carry_over;
            
            if(sum > 9) {
                carry_over = 1;
                sum -= 10;
            } else {
                carry_over = 0;
            }
            
            char outcome = intToChar(sum);
            
            res += outcome;
            
            i1--;
        }
        
        while(i2 > -1) {
            int digit2 = charToInt(num2[i2]);
            int sum = digit2 + carry_over;;
            
            if(sum > 9) {
                carry_over = 1;
                sum -= 10;
            } else {
                carry_over = 0;
            }
            
            char outcome = intToChar(sum);
            
            res += outcome;
            
            i2--;
        }
        
        if(carry_over > 0) {
            res += intToChar(carry_over);
        }
        
        std::reverse(res.begin(), res.end());
        return res; 
    }
};