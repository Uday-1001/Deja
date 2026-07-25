// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int ans = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            prod *= nums[i];
            if(prod < 0) prod = 0;
            ans = max(ans , prod);
        }
    return ans;
    }
};