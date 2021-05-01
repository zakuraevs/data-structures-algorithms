// Given two sorted arrays, first array padded with as many 0s as there
// are elements in the second array, merge the two into the first array in ascending order.
// O(n) time, O(1) space

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // edge case of the first array being empty
        // we just copy the second array into first
        if (nums1.size() == nums2.size())
        {
            for (int i = 0; i < n; ++i)
            {
                nums1[i] = std::max(nums1[i], nums2[i]);
            }
        }
        
        // indexes of largest elements in both arrays
        int i1 = m-1;
        int i2 = n-1;
        // index of overall largest element
        int largest = m+n-1;
        
        while (i1 > -1 && i2 > -1)
        {            
            // placing the largest overall element
            // at the end of nums1
            // if it's in nums2, all is clear
            if (nums2[i2] > nums1[i1])
            {
                nums1[largest] = nums2[i2];
                --largest;
                --i2;
                // if it's in nums1, we place
                // it at the end and replace its
                // original value with 0. We will
                // take care of that 0 eventually
                // because i2 hasn't decremented 
                // in this iteration
            } else {
                nums1[largest] = nums1[i1];
                nums1[i1] = 0;
                --largest;
                --i1;
            }
            
        }
        
        // finishing any remaining values from nums2
        while (i2 > -1)
        {
            nums1[largest] = nums2[i2];
            --largest;
            --i2;
        }
    }
};

