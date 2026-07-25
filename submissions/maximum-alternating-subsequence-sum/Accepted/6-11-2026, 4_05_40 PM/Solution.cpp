// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    using ll = long long;
    vector<vector<ll>>dp;

    ll solve(vector<int>&nums , int i , bool iseven)
    {
        //base case
        if(i >= nums.size()) return 0;
        if(dp[i][iseven] != -1) return dp[i][iseven];

        //include case
        ll include = 0;
        ll sum = 0;

        if(iseven) 
            sum += nums[i] + solve(nums , i+1 , false);
        else 
            sum += -nums[i] + solve(nums , i+1 , true);

        include = max(include , sum);

        //exclude case
        ll exclude = 0 + solve(nums , i+1 , iseven);

        return dp[i][iseven] = max(include , exclude);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1 , vector<ll>(2 , -1));

        return solve(nums , 0 , true);
    }
};