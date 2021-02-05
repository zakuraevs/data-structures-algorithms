// Given a string of parentheses,
// check if it is valid.
// O(n) time, O(n) space

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<int> open_parens;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            char current = s[i];
            if(current == '[' || current == '{'|| current == '(')
                open_parens.push(current);
            else {
                if(open_parens.empty())
                    return false;
                char top = open_parens.top();
                open_parens.pop();
                if(!(top == '['&& current == ']' ||
                   top == '{' && current == '}' ||
                   top == '(' && current == ')')
                  )
                    return false;
            } 
        }
        if(open_parens.size() == 0)
            return true;
        else
            return false;
    }
};