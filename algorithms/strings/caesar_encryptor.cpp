// Given an inputs tring of letters,
// shift all of the letters by key and return
// the result string

#include <string>

// Constant time
// We want to map from old char to new
char getNewChar(char c, int key) {
    // a is 97
    // z is 122
    int alphabet_position =  c - 96;

    int new_alphabet_position = alphabet_position + key;
    if(new_alphabet_position > 26) new_alphabet_position %= 26;

    int new_cpp_decimal = new_alphabet_position + 96;
    char new_char = new_cpp_decimal;

    return new_char;
}

// O(n) time and space
std::string caesarCypherEncryptor(std::string str, int key) {

    int n = str.size();
    std::string result = "";

    for(int i = 0; i < n; i++) {
        result.push_back(getNewChar(str[i], key));
    }

    return result;
}