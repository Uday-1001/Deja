// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int n , m;
    int mini = INT_MAX;
    vector<vector<vector<int>>>dp;

    void solve(vector<vector<int>>& grid , int i , int j , int sum) 
    {
        if(i >= n or j >= m) return;

        if(i == n-1 and j == m-1)
        {
            mini = min(mini , sum + grid[i][j]);
            return;
        }

        if(dp[i][j][sum] != -1) return;

        dp[i][j][sum] = 1;
        solve(grid , i+1 , j , sum + grid[i][j]);
        solve(grid , i , j+1 , sum + grid[i][j]);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int total = (m * n * 200) + 1;

        dp.resize(n+1 , vector<vector<int>>(m+1 , vector<int>(total , -1)));

        solve(grid , 0 , 0 , 0);
        return mini;
    }
};