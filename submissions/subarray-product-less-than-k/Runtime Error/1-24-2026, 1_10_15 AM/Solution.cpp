// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int suffix = 1;
        int num = 1;

        for(int i = 0 ; i <nums.size() ; i++)
        {
            num *= nums[i];
            if(num < k) count++;
            else 
            {
                num /= suffix;
                if(num < k) count++;
            }
            suffix *= nums[i];
        }
    return count*2;
    }
};