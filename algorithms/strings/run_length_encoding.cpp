// Given an inputs string of letters,
// encode it in the format where before each
// letter, the number of running repetitions 1-9 of this letter
// are given, then the letter itself

// O(n) time and space
#include <string>
string runLengthEncoding(string str) {
	// Precompute size of str
	int n = str.size();
	// Initialize the result
	std::string res = "";
	
	// Going to iterate over str in O(n)
	int i = 0;
	while(i < n) {
		// Take current character
		char current = str[i];
		// Initialize prefix of charracter
		int prefix = 1;
		
		// While we are in bounds, the next character is the same as current
		// and prefix is less than 9,
		// we keep going, incrementing prefix and i
		while((i + 1) < n && str[i + 1] == str[i] && prefix < 9) {
			prefix++;
			i++;
		}
		
		// Add prefix and character to the result
		res += std::to_string(prefix);
		res.push_back(current);

		// Advance
		i++;
	}
  return res;
}
