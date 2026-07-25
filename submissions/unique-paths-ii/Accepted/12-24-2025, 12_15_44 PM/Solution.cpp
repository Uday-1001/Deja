// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int n , m;
    int byrec(vector<vector<int>>& obstacleGrid , int i , int j , vector<vector<int>>&dp)
    {
        if(i >= m or j >= n or obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int down = byrec(obstacleGrid , i+1 , j , dp);
        int right = byrec(obstacleGrid , i , j+1 , dp);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , -1));
        return byrec(obstacleGrid , 0 , 0 , dp);
    }
};