// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int n , m;

    int BFS(vector<vector<int>>& grid)
    {
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;

                    int area = 0;

                    while(!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        area++;

                        for(int k = 0; k < 4; k++)
                        {
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(nr >= 0 && nr < m and nc >= 0 and nc < n and grid[nr][nc] == 1 and !vis[nr][nc])
                            {
                                vis[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
    return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        return BFS(grid);
    }
};