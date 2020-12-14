#include <unordered_map>

/*
* Helper function for conversion of roman numeral strings to
* their decimal string representations
* runs in constant time and space so long as we limit roman 
* input values to the range 1 - 50.
*/
std::string romanToDec(std::string& roman) {
    std::unordered_map<char, int> char_to_int = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}
    };
    
    int n = roman.size();
    int integer_value = 0;
    for(int i = 0; i < n; ++i) {
        if(char_to_int[roman[i+1]] <= char_to_int[roman[i]]) 
            integer_value += char_to_int[roman[i]];
        else 
            integer_value -= char_to_int[roman[i]];
    } 
    return std::to_string(integer_value);
}

/*
* Helper function for conversion of decimal number strings to
* their roman numeral string representations
* runs in constant time and space so long as we limit roman 
* input values to the range 1 - 50.
*/
std::string decToRoman(std::string& dec_string) {
    std::vector<int> numbers = {1, 4, 5, 9, 10, 40, 50};
    std::vector<std::string> symbols = {"I", "IV", "V", "IX", "X", "XL", "L"};
    
    int decimal = std::stoi(dec_string);
    std::string res;
    int i = 6;
    while(decimal > 0) {
        int div = decimal / numbers[i];
        decimal = decimal % numbers[i];
        while(div > 0) {
            res += symbols[i];
            --div;
        }
        --i;
    }
    return res;
}


/*
* The function has O(s * nlogn) time and space complexities,
* where s is the length of the longest string in the input vector
* and n is the length of the vector.
* Constant space complexity could be achieved by altering 
* the initial input vector instead of creating a copy.
*/
vector<string> getSortedList(const vector<string>& names) {
    
    // Checking for empty input
    if(names.size() == 0) return names;
    
    // Since the input is constant, we create a copy.
    // Otherwise constant space complexity could be achieved.
    vector<string> names_temp = names;
    
    // Running a for loop in O(n) time over all the monarch names.
    for(std::string& monarch : names_temp) {
        
        // Finding starting and ending indices of the roman numeral.
        int roman_start = 0;
        int roman_end = monarch.size() - 1;
        char current = monarch[roman_start];
        while(current != ' ') {
            ++roman_start;
            current = monarch[roman_start];
        }
        ++roman_start;
        current = monarch[roman_start];
        
        // Storing the roman numeral as a string.
        std::string roman_string = monarch.substr(roman_start, roman_end);
        // And creating a decimal string representation.
        std::string decimal_string = romanToDec(roman_string);
        
        // Replacing the roman version with decimal.
        monarch = monarch.substr(0, roman_start);
        monarch += decimal_string;
    }
    
    // Sorting the updated vector in ascending lexycographic order. O(s*nlogn)
    std::sort(names_temp.begin(), names_temp.end());
    
    // Doing backwards substritution of roman numerals instead of decimal.
    for(std::string& monarch : names_temp) {
        int decimal_start = 0;
        int decimal_end = monarch.size() - 1;
        char current = monarch[decimal_start];
        while(current != ' ') {
            ++decimal_start;
            current = monarch[decimal_start];
        }
        ++decimal_start;
        current = monarch[decimal_start];
        
        std::string decimal_string = monarch.substr(decimal_start, decimal_end);
        std::string roman_string = decToRoman(decimal_string);
        
        monarch = monarch.substr(0, decimal_start);
        monarch += roman_string;
    }
    
    return names_temp;
}