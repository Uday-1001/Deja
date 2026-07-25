// https://leetcode.com/problems/detect-cycles-in-2d-grid

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n , vector<bool>(m , false));
        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(vis[i][j]) continue;

                queue<tuple<int,int,int,int>>q;
                q.push({i , j , -1 , -1});
                vis[i][j] = true;

                while(!q.empty())
                {
                    auto[row , col , parentr , parentc] = q.front();
                    q.pop();

                    for(int k = 0 ; k<4 ; k++)
                    {
                        int newr = row + dr[k];
                        int newc = col + dc[k];

                        if(newr >= 0 and newr < n and newc >= 0 and newc < m and grid[newr][newc] == grid[row][col])
                        {
                            if(!vis[newr][newc])
                            {
                                q.push({newr , newc , row , col});
                                vis[newr][newc] = true;
                            }
                            else if(newr != parentr or newc != parentc) return true;
                        }
                    }
                }
            }
        }
    return false;
    }
};