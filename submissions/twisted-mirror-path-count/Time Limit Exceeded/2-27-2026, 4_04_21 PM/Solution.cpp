// https://leetcode.com/problems/twisted-mirror-path-count

class Solution {
public:
    int paths = 0;
    const int mod = 1e9+7;

    bool isValid(vector<vector<int>>& grid , int &x , int &y , bool &isright)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        while(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1)
        {
            //found a mirror
            if(isright)
            {
                x = x+1;
                isright = false;
            }
            else 
            {
                y = y+1;
                isright = true;
            }
        }

        if(x >= 0 and x < n and y >= 0 and y < m) return true;
        return false;
    }

    void solve(vector<vector<int>>& grid , int i , int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 or i >= n or j < 0 or j >= m) return;

        if(i == n-1 and j == m-1)
        {
            paths = (paths + 1) % mod;
            return;
        }

        //going right
        if(j+1 < m)
        {
            bool isright = true;
            int x = i;
            int y = j+1;

            if(isValid(grid , x , y , isright)) solve(grid , x,  y);
        }
        
        //going down
        if(i+1 < n)
        {
            bool isright = false;
            int x = i+1;
            int y = j;

            if(isValid(grid , x , y , isright)) solve(grid , x,  y);
        }
    }

    int uniquePaths(vector<vector<int>>& grid) {
        solve(grid , 0 , 0);
        return paths;
    }
};