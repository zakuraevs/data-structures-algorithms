// Given an array of integers,
// find the the largest sum of a contiguous subarray
// O(n) tume, constant space

        // Precompute size of the array
        int n = nums.size();
        if(n == 0) return -1;
        
        // This variable will track the max sum
        // The best we can do for an array of length 1 is just the first element
        int max_sum = nums[0];
        // The subarray we're currently looking at
        int current = nums[0];
        
        // Iterating over all the elements of the input array
        for(int i=1; i<n; i++) {
            // We have two choices:
            // 1. continue the current subarray
            // 2. Start anew with the current element
            current = max(current + nums[i], nums[i]);
            max_sum = max(current, max_sum);
        }
        return max_sum;
    }
};