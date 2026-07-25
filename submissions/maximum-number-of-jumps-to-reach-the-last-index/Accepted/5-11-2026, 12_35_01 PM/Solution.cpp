// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index

class Solution {
public:
    using ll = long long;
    int n;
    vector<ll>dp;

    int bytab(vector<int>&nums , int &target)
    {
        vector<ll>dp(n+1 , -1);
        dp[n-1] = 0;

        for(int i = n-2 ; i >= 0 ; i--)
        {
            ll ans = -1;
            for(int j = i+1 ; j<n ; j++)
            {
                if(dp[j] == -1) continue;
                ll nextone = nums[j];
                if(nextone - nums[i] >= -target and nextone - nums[i] <= target)
                {
                    ll nextsteps = 1 + dp[j];
                    if(nextsteps != 0) ans = max(ans , nextsteps);
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }

    ll byrec(vector<int>&nums , int i , int &target)
    {
        if(i == nums.size()-1) return 0;
        if(i >= nums.size()) return -1;
        if(dp[i] != -1) return dp[i];

        ll ans = -1;

        for(int j = i+1 ; j<nums.size() ; j++)
        {
            ll nextone = nums[j];
            if(nextone - nums[i] >= -target and nextone - nums[i] <= target)
            {
                ll nextsteps = 1 + byrec(nums , j , target);
                if(nextsteps != 0) ans = max(ans , nextsteps);
            }
        }
        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        // dp.assign(nums.size()+1 , -1);
        // ll ans = byrec(nums , 0 , target);
        // return ans;

        return bytab(nums , target);
    }
};