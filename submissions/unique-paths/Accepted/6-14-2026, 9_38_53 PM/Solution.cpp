// https://leetcode.com/problems/unique-paths

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int m , int n , int i , int j)
    {
        if(i > m or j > n) return 0;
        if(i == m-1 and j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int right = 0 , down = 0;

        if(j < n) down = solve(m , n , i+1 , j);
        if(i < m) right = solve(m , n , i , j+1);
       
        return dp[i][j] = right + down;   
    }

    int uniquePaths(int m, int n) {
        dp.resize(m+1 , vector<int>(n+1 , -1));
        return solve(m , n , 0 , 0);
    }
};