// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid

class Solution {
public:
    vector<vector<bool>>vis;

    bool BFS(vector<vector<int>>& grid , int n , int m)
    {
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();

            if(row == n-1 && col == m-1) return true;

            int move = grid[row][col];

            vector<pair<pair<int,int>,vector<int>>>next_moves;

            if(move == 1)
            {
                next_moves = {
                    {{row,col-1},{1,4,6}},
                    {{row,col+1},{1,3,5}}
                };
            }
            else if(move == 2)
            {
                next_moves = {
                    {{row-1,col},{2,3,4}},
                    {{row+1,col},{2,5,6}}
                };
            }
            else if(move == 3)
            {
                next_moves = {
                    {{row,col-1},{1,4,6}},
                    {{row+1,col},{2,5,6}}
                };
            }
            else if(move == 4)
            {
                next_moves = {
                    {{row,col+1},{1,3,5}},
                    {{row+1,col},{2,5,6}}
                };
            }
            else if(move == 5)
            {
                next_moves = {
                    {{row,col-1},{1,4,6}},
                    {{row-1,col},{2,3,4}}
                };
            }
            else
            {
                next_moves = {
                    {{row,col+1},{1,3,5}},
                    {{row-1,col},{2,3,4}}
                };
            }

            for(auto &it : next_moves)
            {
                auto[newr , newc] = it.first;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc])
                {
                    int val = grid[newr][newc];
                    for(auto &x : it.second)
                    {
                        if(x == val)
                        {
                            vis[newr][newc] = true;
                            q.push({newr,newc});
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n , vector<bool>(m , false));

        return BFS(grid , n , m);
    }
};