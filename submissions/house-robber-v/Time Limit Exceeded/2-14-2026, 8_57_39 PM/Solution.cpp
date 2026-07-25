// https://leetcode.com/problems/house-robber-v

class Solution {
public:
    using ll = long long;
    int n;
    
    ll bydp(vector<int>&nums , vector<int>&colors , int i , vector<ll>&dp)
    {
        //base case
        if(i >= nums.size()) return 0;
        
        ll take = nums[i];
        if(i+1 < n && colors[i] == colors[i+1])
        {
            take += bydp(nums , colors , i+2 , dp);
        }
        else take += bydp(nums , colors , i+1 , dp);

        ll skip = 0 + bydp(nums , colors , i+1 , dp);
        
        return dp[i] = max(skip , take);
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        vector<ll>dp(n+1 , -1);
        
        return bydp(nums , colors , 0 ,dp);
    }
};