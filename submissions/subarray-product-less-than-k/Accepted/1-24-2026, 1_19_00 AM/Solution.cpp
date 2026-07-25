// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int prod = 1;
        int count = 0;

        for(int r = 0 ; r<nums.size() ; r++)
        {
            prod *= nums[r];

            //shrinking the window
            while(prod >= k and l <= r) prod /= nums[l++];

            count += (r - l + 1);
        }
    return count;
    }
};