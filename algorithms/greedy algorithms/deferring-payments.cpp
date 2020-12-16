#include <queue>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    
    int sum = 0;
    int switches = 0;
    std::priority_queue<int> payments;

    for( int current : A) {
        sum += current;
        if(current < 0) payments.push(-current);
        if(sum < 0) {
            sum += payments.top();
            payments.pop();
            switches++;
        }
    }

    return switches;
}
