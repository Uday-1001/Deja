// https://leetcode.com/problems/find-a-safe-walk-through-a-grid

class Solution {
public:
    int n , m;
    vector<vector<bool>>vis;
    vector<vector<vector<int>>>dp;

    bool byrec(vector<vector<int>>&grid , int health , int i , int j)
    {
        if(i >= n or j >= m or i < 0 or j < 0 or vis[i][j]) return false;

        if(grid[i][j] == 1) health--;
        if(health < 1) return false;

        if(i == n-1 and j == m-1) return true;
        if(dp[i][j][health] != -1) return dp[i][j][health];

        vis[i][j] = true;

        bool up = byrec(grid , health , i-1 , j);
        bool down = byrec(grid , health , i+1 , j);
        bool left = byrec(grid , health , i , j-1);
        bool right = byrec(grid , health , i , j+1);

        //backtracking to reset the path for next exploration
        vis[i][j] = false;

        return dp[i][j][health] = (up or down or left or right);
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();

        vis.resize(n , vector<bool>(m , false));
        dp.resize(n+1 , vector<vector<int>>(m+1 , vector<int>(health + 1 , -1)));

        return byrec(grid , health , 0 , 0);
    }
};