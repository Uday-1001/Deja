// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>grid(n , vector<int>(m , 0));

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++) grid[i][j] = mat[i][j];
        }

        k = k % grid[0].size();
        for(int i = 0 ; i<n ; i++)
        {
            if(i % 2 == 0) rotate(grid[i].begin() , grid[i].begin() + k , grid[i].end());
            else rotate(grid[i].begin() , grid[i].end() - k , grid[i].end());
        }
    
        return grid == mat ? true : false;
    }
};