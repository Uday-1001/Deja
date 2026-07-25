// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    using pi = pair<int,int>;
    int n , m;
    vector<vector<bool>> vis;

    void BFS(vector<vector<char>>& grid , int r , int c)
    {
        queue<pi>q;
        q.push({r , c});
        vis[r][c] = true;
        
        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        while(!q.empty())
        {
            auto[row , col] = q.front();
            q.pop();

            for(int k = 0 ; k<4 ; k++)
            {
                int newr = row + dr[k];
                int newc = col + dc[k];

                if(newr >= 0 and newr < n and newc >= 0 and newc < m and grid[newr][newc] == '1' and !vis[newr][newc])
                {
                    q.push({newr , newc});
                    vis[newr][newc] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<bool>>(n , vector<bool>(m , false));
        int ans = 0;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j] == '1' and !vis[i][j])
                {
                    BFS(grid , i , j);
                    ans++;
                }
            }
        }
    return ans;
    }
};