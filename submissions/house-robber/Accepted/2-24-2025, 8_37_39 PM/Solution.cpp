// https://leetcode.com/problems/house-robber

class Solution {
public:
    int solve (vector<int>&dp,vector<int>& nums ,int n, int i)
    {
        if(i >= n){
        return 0 ;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int includeAns = nums[i] + solve(dp,nums,n,i+2);
        int excludeAns = solve(dp,nums,n,i+1);

        dp[i] = max(includeAns,excludeAns);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        vector<int>dp(nums.size()+1 , -1);
        int ans = solve(dp,nums,nums.size(),index);
        return ans;
    }
};