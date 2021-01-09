
#include <algorithm>
#include <limits.h>


int solution(vector< vector<int> > &A) {

    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();

    // inner vector: {value, row, column}
    std::vector< std::vector<int> > values;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            std::vector<int> current_cell = {A[row][col], row, col};
            values.push_back(current_cell);
        }
    }

    std::sort(values.begin(), values.end(), 
            [](const std::vector<int>& first, const std::vector<int>& second) {
                return first[0] > second[0];
    });


    int sum = INT_MIN;

    // BAD, FIX
    for(std::vector<int> i : values) {
        for(std::vector<int> j : values) {
            if(i[0] + j[0] > sum && i[1] != j[1] && i[2] != j[2]) sum = i[0] + j[0];
        }
    }

    return sum;

}