// https://leetcode.com/problems/house-robber

class Solution {
public:
    int byrec(vector<int>&nums , int i , vector<int>&dp)
    {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int include = nums[i] + byrec(nums , i+2 , dp);
        int exclude = 0 + byrec(nums , i+1 , dp);

        return dp[i] = max(include , exclude);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);
        return byrec(nums , 0 , dp);
    }
};