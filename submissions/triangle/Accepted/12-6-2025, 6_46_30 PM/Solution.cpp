// https://leetcode.com/problems/triangle

class Solution {
public:
    int bytab(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        for(int col = 0 ; col < n ; col++)
        {
            dp[n-1][col] = triangle[n-1][col];
        }

        for(int row = n-2 ; row >= 0 ; row --)
        {
            for(int col = row ; col >= 0 ; col --)
            {
                int op1 = triangle[row][col] + dp[row+1][col];
                int op2 = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(op1 , op2);
            }
        }
    return dp[0][0];
    }

    // int solve(vector<vector<int>>& triangle , int row , int col , vector<vector<int>>&dp)
    // {
    //     if(row == triangle.size()-1) return triangle[row][col];
    //     if(dp[row][col] != -1) return dp[row][col];

    //     int op2 = triangle[row][col] + solve(triangle , row+1 , col , dp);
    //     int op1 = triangle[row][col] + solve(triangle , row+1 , col+1 , dp);

    //     return dp[row][col] = min(op1 , op2);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;

        // vector<vector<int>>dp(n , vector<int>(n , -1));
        // return solve(triangle, 0 , 0 , dp);

        return bytab(triangle);
    }
};