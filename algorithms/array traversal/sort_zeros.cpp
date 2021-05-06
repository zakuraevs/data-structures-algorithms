// Given a vector of integers,
// put all the zeros at the end,
// while maintaining the realative order
// of all other elements
// O(n) time, O(1) space

#include <vector>

void moveZeroes(vector<int>& nums) {
        
        // find the first nonzero
        // find the first zero
        // swap
        // move first nonzero index right
        // move first zero index right
        
        // [0,1,0,3,12]
        // [1,0,0,3,12]
        // [1,3,0,0,12]
        // [1,3,0,0,12]

        
        size_t n = nums.size();
        int first_zero = 0;
        int first_nonzero = 0;
        int last_nonzero = n-1;
        
        // actually finding the first zero index
        while (first_zero < n && nums[first_zero] != 0)
        {
            ++first_zero;
        }
        // same for nonzero
        while (first_nonzero < n && nums[first_nonzero] == 0)
        {
            ++first_nonzero;
        }
        // same for last nonzero
        while (last_nonzero > first_nonzero && nums[last_nonzero] == 0)
        {
            --last_nonzero;
        }
        
        // if this condition holds, the array is already sorted
        if (last_nonzero < first_zero) {
            return;
        }
        
        // otherwise run a loop while we're within bounds
        while (first_nonzero < n && first_zero < n)
        {
            // swapping if zero is to the left of nonzero
            if (first_zero < first_nonzero)
            {
                nums[first_zero] = nums[first_nonzero];
                nums[first_nonzero] = 0;
            // just moving on to the next nonzero element otherwise
            // since the current one is already in its place
            } else {
                ++first_nonzero;                
            }

            // looking for the next zero element
            while (first_zero < n && nums[first_zero] != 0)
            {
                ++first_zero;
            }
            
            
            // looking for the next nonzero element
            while (first_nonzero < n && nums[first_nonzero] == 0)
            {
                ++first_nonzero;
            }
        }
    }