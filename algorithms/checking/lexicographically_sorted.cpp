// Giveb a lexicographic ordering of characters
// and an array of words, check whethere all the words
// in the array are soreted in lexicographical order
// O(n) time O(m) space where n is the total number
// of characters in all the words and m is the number
// of characters in the alphabet

#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        
        std::unordered_map<char, int> chars_to_positions;
        int char_count = order.size();
        int word_count = words.size();
        
        for(int i = 0; i < char_count; i++) {
            chars_to_positions[order[i]] = i;
        }
        
        for(int i = 1; i < word_count; i++) {
            
            int current_size = words[i].size();
            int prev_size = words[i - 1].size();
            
            int j = 0;
            while(j < current_size && j < prev_size) {
                if(chars_to_positions[words[i-1][j]] < chars_to_positions[words[i][j]])
                    break;
                if(chars_to_positions[words[i][j]] < chars_to_positions[words[i-1][j]])
                   return false;
                if(j == current_size - 1 && prev_size > current_size)
                    return false;
                j++;
            }
            
        } 
        return true;
    }
};