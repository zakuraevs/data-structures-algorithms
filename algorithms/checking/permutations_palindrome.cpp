// Given a string, checks wheter any of its n! permutations is a palindrome
// in O(n) time and space

#include <iostream>
#include <unordered_map>

bool hasPalindromePermutation(const string& str) {
    // check if any permutation of the input is a palindrome
    std::unordered_map<char, int> chars;

    // O(n)
    for(char c : str) {
        chars[c]++;
    }

    bool found_odd = false;

    // O(n)
    for(std::pair<char, int> p : chars) {
        if(p.second % 2 != 0) {
            if(found_odd) return false;
            found_odd = true; 
        }
    }

    return true;
}