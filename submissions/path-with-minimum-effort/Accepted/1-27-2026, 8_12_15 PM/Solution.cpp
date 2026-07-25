// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    using ppi = pair<int, pair<int,int>>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n , vector<int>(m , INT_MAX));
        dist[0][0] = 0;

        priority_queue<ppi , vector<ppi> , greater<ppi>>pq;
        pq.push({0, {0 , 0}});

        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        while(!pq.empty())
        {
            auto[effort , cell] = pq.top();
            pq.pop();
            auto[row , col] = cell;

            if(row == n-1 and col == m-1) return effort;

            for(int i = 0 ; i<4 ; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 and newr < n and newc >= 0 and newc < m)
                {
                    int diff = abs(heights[newr][newc] - heights[row][col]);
                    int net_effort = max(effort , diff);

                    if(net_effort < dist[newr][newc])
                    {
                        dist[newr][newc] = net_effort;
                        pq.push({net_effort , {newr , newc}});
                    }
                }
            }
        }
    return 0;
    }
};