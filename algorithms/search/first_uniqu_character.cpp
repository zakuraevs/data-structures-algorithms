// a linear time constant space algo to find the index 
// of the first nonrepeating character in a string

// my hashmap solution
int firstUniqChar(std::string s) {

    int len = s.size();
    std::unordered_map<char, int> found_characters;

    for(int i=0; i<len; i++){
        found_characters[s[i]]++;
    }

    for(int i=0; i<len; i++){
        if(found_characters[s[i]] < 2) {
            return i;
        }
    }

    return -1;
}

// another solution using C++ built in methods
int firstUniqChar(string s) {

	for (int i = 0; i < s.length(); i++)
		if (s.find(s[i]) == s.find_last_of(s[i]))
			return i;

	return -1;
}
