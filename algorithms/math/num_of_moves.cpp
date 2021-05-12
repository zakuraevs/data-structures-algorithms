// Given a vector of integers,
// find the minimum number of moves to make 
// all elements equal, where one move means
// incrementing any n-1 elements by 1
// O(n) time, constant space

#include <vector>

int minMoves(std::vector<int> &nums)
{

    size_t n = nums.size();
    int moves = 0;
    int min = nums[0];

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        moves += nums[i] - min;
    }

    return moves;
}