// Given a vector of strings where each string is a vector, 
// sort them according to rules (https://leetcode.com/problems/reorder-data-in-log-files/)
// O(cnlogn) time O(n*m) space, where n is the length of input array, m is the length of the longest
// string in it, c is the length of the longest letter log.

struct compare_letter_logs {
        
        inline bool operator() (string l1, string l2) {
            int n1 = l1.size();
            int n2 = l2.size();

            int i1 = 0;
            int i2 = 0;

            while(l1[i1++] != ' ');// i1++;
            while(l2[i2++] != ' ');// i2++;

            while (i1 < n1 && i2 < n2) {
                if(l1[i1] < l2[i2]) return true;
                if (l1[i1] > l2[i2]) return false;
                i1++;
                i2++;
            }

            if (n1 != n2)
                return n1 < n2 ? true : false;

            i1 = 0;
            i2 = 0;

            string s1;
            string s2;

            while(l1[i1++] != ' ') 
                s1 += l1[i1];
            while(l2[i2++] != ' ') 
                s2 += l1[i1];

            return s1 < s2 ? true : false;
        }
        
    };
    
    bool is_digit_log(std::string s) {
        int i = 0;
        while(s[++i] != ' ');
        i++;
        
        return isdigit(s[i]);
    }
        
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> letter_logs;
        vector<string> digit_logs;
        
        for (auto l : logs) {
            if (is_digit_log(l))
                digit_logs.push_back(l);
            else
                letter_logs.push_back(l);
        }
                
        std::sort(letter_logs.begin(), letter_logs.end(), compare_letter_logs());
        
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
