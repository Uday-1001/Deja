// https://leetcode.com/problems/triangle

class Solution {
public:
    int solve(vector<vector<int>>& triangle , int row , int col , vector<vector<int>>&dp)
    {
        if(row == triangle.size()) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int mini = INT_MAX;
        int op1 = triangle[row][col] + solve(triangle , row+1 , col+1 , dp);
        int op2 = triangle[row][col] + solve(triangle , row+1 , col , dp);

        int optimal = min(op1 , op2);
        mini = min(mini , optimal);

        return dp[row][col] = mini;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return solve(triangle, 0 , 0 , dp);
    }
};