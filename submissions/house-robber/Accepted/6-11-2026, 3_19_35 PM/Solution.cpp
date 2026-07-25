// https://leetcode.com/problems/house-robber

class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums , int i)
    {
        //base case 
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums , i+2);
        int not_take = 0 + solve(nums , i+1);

        return dp[i] = max(take , not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1 , -1);

        return solve(nums , 0);
    }
};