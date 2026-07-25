// https://leetcode.com/problems/house-robber-iv

class Solution {
public:
    int bydp(vector<int>&nums, int i , int k , vector<vector<int>>&dp)
    {
        if(k == 0) return 0;
        if(i >= nums.size()) return INT_MAX;
        if(dp[i][k] != -1) return dp[i][k];

        //ek case hum solve karenge
        int take = max(nums[i] , bydp(nums , i+2 , k-1 , dp));
        int skip = bydp(nums , i+1 , k , dp);

        return dp[i][k] = min(take , skip);
    }

    int minCapability(vector<int>& nums, int k) {
        vector<vector<int>>dp(nums.size() + 1 , vector<int>(k+1 , -1));
        return bydp(nums , 0 , k , dp);
    }
};