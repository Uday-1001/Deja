// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) 
        {
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            ans = max(ans, max(prefix, suffix));

            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }

        return ans;
    }
};