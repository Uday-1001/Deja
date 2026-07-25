// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int byrec(int m  , int n , int i , int j , vector<vector<int>>&dp)
    {
        //base case
        if(i > m or j > n) return 0;
        if(i == m-1 and j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        //down
        int down = byrec(m , n , i+1 , j , dp);
        //right
        int right = byrec(m , n , i , j+1 , dp);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , -1));
        return byrec(m , n , 0 , 0 , dp);
    }
};