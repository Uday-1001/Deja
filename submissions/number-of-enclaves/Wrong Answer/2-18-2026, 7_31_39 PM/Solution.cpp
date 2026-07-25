// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    using pi = pair<int,int>;

    bool isValid(int row , int col , vector<vector<int>>&grid , vector<vector<bool>>&vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 or row >= n or col < 0 or col >= m or grid[row][col] != 1 or vis[row][col] == true) 
            return false;
        return true;
    }

    int BFS(vector<vector<int>>& grid , vector<vector<bool>>&vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pi>q;
        int valid_ones = 0;
        int total_ones = 0;
        
        for(int i = 0 ; i<n ; i++) 
        {
            if(grid[i][0] == 1 and !vis[i][0])
            {
                valid_ones++;
                q.push({i , 0});
                vis[i][0] = true;
            }
            else if(grid[i][m-1] == 1 and !vis[i][m-1])
            {
                valid_ones++;
                q.push({i , m-1});
                vis[i][m-1] = true;
            }
        }

        for(int j = 0 ; j<m ; j++) 
        {
            if(grid[0][j] == 1 and !vis[0][j])
            {
                valid_ones++;
                q.push({0 , j});
                vis[0][j] = true;
            }
            else if(grid[n-1][j] == 1 and !vis[n-1][j])
            {
                valid_ones++;
                q.push({n-1 , j});
                vis[n-1][j] = true;
            }
        }

        for(auto it : grid) for(auto cell : it) if(cell == 1) total_ones++;
        
        
        int remaining = total_ones - valid_ones;
        while(!q.empty())
        {
            auto [row , col] = q.front(); 
            q.pop();

            vector<int>dr = {-1 , 1 , 0 , 0};
            vector<int>dc = {0 , 0 , 1 , -1};

            for(int i = 0 ; i<4 ; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(isValid(newr , newc , grid , vis))
                {
                    remaining--;
                    q.push({newr , newc});
                    vis[newr][newc] = true;
                }
            }
        }
        return remaining;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        return BFS(grid , vis);
    }
};