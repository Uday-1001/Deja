// https://leetcode.com/problems/minimum-path-sum

class Solution {
public: 
    int mini = INT_MAX;
    int byrec(vector<vector<int>>& grid , int i, int j , vector<vector<int>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        //base case 
        if(i == n-1 and j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        //ek case hum solve karenge
        //go right
        if(i == n-1)
        {
            return dp[i][j] = grid[i][j] + byrec(grid , i , j+1 , dp);
        }
        else if(j == m-1)
        {
            return dp[i][j] = grid[i][j] + byrec(grid , i+1 , j , dp);
        }
        else
        {
            return dp[i][j] = grid[i][j] + min(byrec(grid , i , j+1 , dp) , byrec(grid , i+1 , j , dp));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

        return byrec(grid , 0 , 0 , dp);   
    }
};