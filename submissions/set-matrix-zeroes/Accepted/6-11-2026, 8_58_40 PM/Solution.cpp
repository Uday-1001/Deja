// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setRowAndCol(vector<vector<int>>& matrix , int i , int j , int n , int m)
    {   
        //set the rows val to zero
        for(int col = 0 ; col<m ; col++)
        {
            if(matrix[i][col] != 0) matrix[i][col] = 1e8;
        }
        //set the col vals to zero
        for(int row = 0 ; row<n ; row++)
        {
            if(matrix[row][j] != 0) matrix[row][j] = 1e8;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0; j<m ; j++)
            {
                int cell = matrix[i][j];
                if(cell == 0) setRowAndCol(matrix , i , j , n , m);
            }
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0; j<m ; j++)
            {
                int cell = matrix[i][j];
                if(cell == 1e8) matrix[i][j] = 0;
            }
        }
    }
};