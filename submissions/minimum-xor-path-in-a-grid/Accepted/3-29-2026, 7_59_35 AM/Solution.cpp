// https://leetcode.com/problems/minimum-xor-path-in-a-grid

class Solution {
public:
    void byrec(vector<vector<int>>& grid , int i , int j , int sum , int &mini , vector<vector<vector<int>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(dp[i][j][sum] != -1) return;
        
        // dp[i][j][sum] = 1;
        
        if(i == n-1 and j== m-1){
            mini = min(mini , sum);
            return;
        }

        if(j+1 < m)
        {
            byrec(grid , i , j+1 , sum ^ grid[i][j+1] , mini , dp);
        }
        if(i+1 < n)
        {
            byrec(grid , i+1 , j , sum ^ grid[i+1][j] , mini , dp);
        }
        dp[i][j][sum] = mini;
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mini = INT_MAX;
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(m+1 , vector<int>(1024 , -1)));
        byrec(grid , 0 , 0 , grid[0][0] , mini , dp);
        return mini;
    }
};