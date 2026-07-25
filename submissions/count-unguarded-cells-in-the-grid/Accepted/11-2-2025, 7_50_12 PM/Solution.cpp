// https://leetcode.com/problems/count-unguarded-cells-in-the-grid

class Solution {
public:
    void markingAll(vector<vector<int>>&grid , vector<vector<int>>& guards , vector<vector<int>>& walls)
    {
        for(auto guard : guards)
        {
            int g_row = guard[0];
            int g_col = guard[1];
            grid[g_row][g_col] = 1;
        }

        for(auto wall : walls)
        {
            int w_row = wall[0];
            int w_col = wall[1];
            grid[w_row][w_col] = 2;
        }

    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m , vector<int>(n , 0));

        markingAll(grid , guards , walls);        

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int curr_cell = grid[i][j];
                if(curr_cell == 1)
                {
                    for(int row = i+1 ; row < m && grid[row][j] != 1 && grid[row][j] != 2 ; row++)
                    {
                        grid[row][j] = 3;
                    }
                    for(int col = j+1 ; col < n && grid[i][col] != 1 && grid[i][col] != 2 ; col++)
                    {
                        grid[i][col] = 3;
                    }
                    for(int row = i-1 ; row >= 0 && grid[row][j] != 1 && grid[row][j] != 2 ; row--)
                    {
                        grid[row][j] = 3;
                    }
                    for(int col = j-1 ; col >= 0 && grid[i][col] != 1 && grid[i][col] != 2 ; col--)
                    {
                        grid[i][col] = 3;
                    }
                }
            }
        }
        int count = 0;
        for(auto row: grid)
        {
            for(auto elem : row)
            {
                if(elem == 0) count++;
            }
        }

        return count;
    }
};