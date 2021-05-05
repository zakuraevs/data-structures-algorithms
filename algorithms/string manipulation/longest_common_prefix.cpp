// Given a vector of strings, find the longest common preifx
// O(n*m) time, O(m) space where n is the the number of strings
// and m is the length of the longest string.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    std::string prefix = strs[0];
    size_t n = strs.size();

    for (int i = 1; i < n; ++i)
    {
        size_t m = std::min(strs[i].size(), prefix.size());
        std::string new_prefix = "";

        for (int j = 0; j < m; ++j)
        {
            if (prefix[j] != strs[i][j])
            {
                break;
            }
            new_prefix.push_back(prefix[j]);
        }
        prefix = new_prefix;
    }
    return prefix;
}
