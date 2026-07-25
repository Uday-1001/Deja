// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    const int mod = 1e9 + 7;
    vector<string>colors = {"RYR" , "RYG" , "RGR" , "RGY" , "YRY" , "YRG" , "YGR" , "YGY" , "GRY" , "GRG" , "GYR" , "GYG"};

    int solve(int n , int prev , vector<vector<int>>&dp)
    {
        //base case
        if(n == 0) return 1;
        if(dp[n][prev] != -1) return dp[n][prev];

        int result = 0;

        for(int i = 0 ; i<12 ; i++)
        {
            bool same_color = false;
            for(int j = 0 ; j<3 ; j++)
            {
                int curr_pattern = colors[i][j];
                int prev_pattern = colors[i][prev];
                if(curr_pattern == prev_pattern)
                {
                    same_color = true;
                    break;
                }
            }
            if(!same_color)
            {
                result = (result + solve(n-1 , i , dp)) % mod;
            }
        }
    return dp[n][prev] = result;
    }

    int numOfWays(int n) {
        vector<vector<int>>dp(n , vector<int>(n , -1));

        int ans = 0;
        for(int i = 0 ; i<12 ; i++)
        {
            ans = (ans + solve(n-1 , i , dp)) % mod;
        }
    return ans;
    }
};