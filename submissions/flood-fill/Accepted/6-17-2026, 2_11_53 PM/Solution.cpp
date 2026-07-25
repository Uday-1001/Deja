// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>newimage = image;

        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n , vector<bool>(m , false));

        q.push({sr , sc});
        vis[sr][sc] = true;

        vector<int>dr = {-1 , 1 , 0 , 0};
        vector<int>dc = {0 , 0 , 1 , -1};

        int srccolor = image[sr][sc];
        newimage[sr][sc] = color;

        if(image[sr][sc] == color) return image;

        while(!q.empty())
        {
            auto[row , col] = q.front();
            q.pop();

            for(int k = 0 ; k<4 ; k++)
            {
                int newrow = dr[k] + row;
                int newcol = dc[k] + col;

                if((newrow < n and newrow >= 0 and newcol < m and newcol >= 0) and (srccolor == image[newrow][newcol]) and !vis[newrow][newcol])
                {
                    newimage[newrow][newcol] = color;
                    vis[newrow][newcol] = true;
                    q.push({newrow , newcol});
                }
            }
        }
        return newimage;
    }
};