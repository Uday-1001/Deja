// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    bool isValid(int i , int j , vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != 1) return false;
        return true;
    }

    int BFS(vector<vector<int>>& grid , int  i ,int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        int freshoranges = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j] == 2) q.push({i , j});
                else if(grid[i][j] == 1) freshoranges++;
            }
        }

        if(freshoranges == 0) return 0;

        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            bool anyrotten = false;

            while(size--)
            {
                auto[row , col] = q.front(); q.pop();

                for(int k = 0 ; k<4 ; k++)
                {
                    int new_row = dr[k] + row;
                    int new_col = dc[k] + col;

                    if(isValid(new_row , new_col , grid))
                    {
                        grid[new_row][new_col] = 2;
                        anyrotten = true;
                        freshoranges--;
                        q.push({new_row , new_col});
                    }
                }
            } 
            if(anyrotten) time++;
        }
    return freshoranges == 0 ? time : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        return BFS(grid , 0 , 0);
    }
};