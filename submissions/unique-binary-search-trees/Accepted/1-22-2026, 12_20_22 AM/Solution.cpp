// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public: 
    int bymemo(int n , vector<int>&dp)
    {
        if(n == 1 or n == 0) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            ans += bymemo(i - 1 , dp) * bymemo(n - i , dp);
        }
        return dp[n] = ans;
    }

    int solve(int n)
    {
        if(n == 1 or n == 0) return 1;

        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            ans += solve(i - 1) * solve(n - i);
        }
        return ans;
    }

    int numTrees(int n) {
        // return solve(n);

        vector<int>dp(n+1 , -1);
        return bymemo(n , dp);
    }
};