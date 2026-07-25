// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:
    int dp[51][51][2501];

    bool isSafe(vector<vector<int>>& grid , vector<vector<bool>>& vis , int &x , int &y , int &n)
    {
        if(x >= n || x < 0 || y >= n || y < 0 || vis[x][y] == true)
            return false;

        return true;
    }

    int solve(vector<vector<int>>& grid , vector<vector<bool>>& vis , int &sx , int &sy , int&n , int max_time)
    {
        // base case
        if(sx == n-1 and sy == n-1) return max_time;

        if(dp[sx][sy][max_time] != -1) return dp[sx][sy][max_time];
        
        //ek case hum solve karenge 
        int ans = INT_MAX;

        //move up
        int x = sx - 1;
        int y = sy;

        if(isSafe(grid , vis , x , y , n))
        {
            vis[x][y] = true;
            ans = min(ans , solve(grid , vis , x , y , n , max(max_time , grid[x][y])));
            vis[x][y] = false;
        }
        
        //move down
        x = sx + 1;
        y = sy;

        if(isSafe(grid , vis , x , y , n))
        {
            vis[x][y] = true;
            ans = min(ans , solve(grid , vis , x , y , n , max(max_time , grid[x][y])));
            vis[x][y] = false;
        }

        //move left
        x = sx;
        y = sy - 1;

        if(isSafe(grid , vis , x , y , n))
        {
            vis[x][y] = true;
            ans = min(ans , solve(grid , vis , x , y , n , max(max_time , grid[x][y])));
            vis[x][y] = false;
        }

        //move right
        x = sx;
        y = sy + 1;

        if(isSafe(grid , vis , x , y , n))
        {
            vis[x][y] = true;
            ans = min(ans , solve(grid , vis , x , y , n , max(max_time , grid[x][y])));
            vis[x][y] = false;
        }

        return dp[sx][sy][max_time] = ans;
    }

    int swimInWater(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));

        int n = grid.size();
        vector<vector<bool>>vis(n , vector<bool>(n , false));

        vis[0][0] = true;
        int max_time = grid[0][0];
        int x = 0;
        int y = 0;

        return solve(grid , vis , x , y , n , max_time);
    }
};