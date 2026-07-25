// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int n , m;
    vector<vector<int>>dp;

    int solve(vector<vector<int>>& grid , int i , int j) 
    {
        if(i >= n or j >= m) return 1e8;

        if(i == n-1 and j == m-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(grid , i , j+1);
        int down = solve(grid , i+1 , j);

        return dp[i][j] = (min(right , down) + grid[i][j]);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n+1 , vector<int>(m+1 , -1));

        return solve(grid , 0 , 0);
    }
};