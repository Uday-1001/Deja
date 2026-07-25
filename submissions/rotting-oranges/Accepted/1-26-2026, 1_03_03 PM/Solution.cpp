// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        int freshones = 0;

        //pushed the rotten ones to maintain intial state of queue and counted freshones
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 2) q.push({i , j});
                else if(grid[i][j] == 1) freshones++;
            }
        }
        if(freshones == 0) return 0;

        //directions array
        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        int time = 0;
        
        //applying BFS here
        while(!q.empty())
        {
            int size = q.size();
            bool anyonerotten = false;
            while(size--)
            {
                auto[row , col] = q.front();
                q.pop();

                for(int i = 0 ; i < 4 ; i++)
                {
                    int newrow = row + dr[i];
                    int newcol = col + dc[i];

                    if(newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and grid[newrow][newcol] == 1)
                    {
                        //rott this orange and push in queue
                        grid[newrow][newcol] = 2;
                        freshones--;
                        anyonerotten = true;
                        q.push({newrow , newcol});
                    }
                }
            }
            if(anyonerotten) time++;
        }
    return (freshones == 0) ? time : -1;
    }
};