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

        k = k % grid.size();
        for(int i = 0 ; i<n ; i++)
        {
            vector<int>&temp = grid[i];

            if(i % 2 == 0) rotate(temp.begin() , temp.begin() + k , temp.end());
            else rotate(temp.begin() , temp.end() - k , temp.end());            
        }
        

        return grid == mat ? true : false;
    }
};