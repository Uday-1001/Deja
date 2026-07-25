// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class Solution {
public:
    
        unordered_map<int, int> mp;

    int byrec(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp){
        // base case
        if(mp.find(arr[curr] + arr[prev]) == mp.end()){
            return 0;
        }
        // if already exist
        if(dp[curr][prev] != -1){
            return dp[curr][prev];
        }
        // 1 case hum solve karenge
        int ans = 1 + byrec(arr, mp[arr[curr] + arr[prev]], curr, dp);
        dp[curr][prev] = ans;
        return dp[curr][prev];
    }


    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
        }
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int curr = j;
                int prev = i;
                maxi = max(maxi, byrec(arr, curr, prev,dp));
            }
        }
        return maxi == 0 ? 0 : maxi + 2;
    }
};