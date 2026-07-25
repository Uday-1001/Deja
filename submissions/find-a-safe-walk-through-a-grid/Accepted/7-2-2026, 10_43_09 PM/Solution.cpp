// https://leetcode.com/problems/find-a-safe-walk-through-a-grid

class Solution {
public:
    int n , m;
    using pi = pair<int,int>;
    vector<vector<int>>dist;

    bool ZeroOneBFS(vector<vector<int>>& grid, int health)
    {
        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        dist[0][0] = grid[0][0];

        deque<pi>dq;
        dq.push_front({0 , 0});

        while(!dq.empty())
        {
            auto[row , col] = dq.front();
            dq.pop_front();

            int cost = dist[row][col];

            for(int k = 0 ; k<4 ; k++)
            {
                int newrow = dr[k] + row;
                int newcol = dc[k] + col;
                if(newrow < 0 || newrow >=n || newcol < 0 || newcol >= m) continue;

                int newcost = grid[newrow][newcol];

                if(cost + newcost < dist[newrow][newcol])
                {
                    dist[newrow][newcol] = cost + newcost;
                    if(newcost == 0) 
                        dq.push_front({newrow , newcol});
                    else 
                        dq.push_back({newrow , newcol});
                }
            }
        }

        int lastcellhealth = dist[n-1][m-1];
        return (health - lastcellhealth) >= 1;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();

        dist.resize(n , vector<int>(m , INT_MAX));

        return ZeroOneBFS(grid , health);
    }
};