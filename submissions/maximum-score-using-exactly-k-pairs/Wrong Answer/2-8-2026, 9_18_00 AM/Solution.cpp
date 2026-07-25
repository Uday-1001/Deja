// https://leetcode.com/problems/maximum-score-using-exactly-k-pairs

class Solution {
public:
    using ll = long long;
    ll solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int k, vector<vector<vector<ll>>>&dp){
        // base case
        if(k==0) return 0;
        if(i >= nums1.size() || j >= nums2.size()) return -1e9;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        ll include = (ll)nums1[i]* (ll)nums2[j] + solve(i+1,j+1,nums1,nums2,k-1,dp);
        ll exc1 = solve(i+1,j,nums1,nums2,k,dp);
        ll exc2 = solve(i,j+1,nums1,nums2,k,dp);
        
        return dp[i][j][k] = max<ll>({include,exc1,exc2});
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<vector<ll>>> dp(101,vector<vector<ll>>(101,vector<ll>(k+1,-1)));
        return solve(0,0,nums1,nums2,k,dp);
    }
};