// Given a string of words only with characters and spaces
// reverses the order of words in the string using a helper function
// O(n) time O(1) space

void reverse(string& str) {
    if (str.empty()) {
        return;
    }

    size_t leftIndex = 0;
    size_t rightIndex = str.length() - 1;

    while (leftIndex < rightIndex) {
        // swap characters
        swap(str[leftIndex], str[rightIndex]);

        // move towards middle
        ++leftIndex;
        --rightIndex;
    }
}

void reverseWords(string& message) {
    reverse(message);

    int len = message.size();
    int i = 0;
    int j = 0;
    int next = 0;

    while(j < len) {
        while(message[j] != ' ' && j != len) ++j;
        next = j+1;
        --j;

        while(i < j) {
            swap(message[i], message[j]);
            ++i;
            --j;
        }

        i = next;
        j = next;
    }
}