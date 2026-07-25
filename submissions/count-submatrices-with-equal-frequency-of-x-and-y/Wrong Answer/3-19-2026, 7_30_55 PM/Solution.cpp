// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>new_grid(n , vector<int>(m , 0));

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j] == 'X') new_grid[i][j] = 1;
                else if(grid[i][j] == 'Y') new_grid[i][j] = -1;
                else new_grid[i][j] = 0; 
            }
        }

        vector<vector<int>>rowpref(n , vector<int>(m , 0));
        vector<vector<int>>colpref(n , vector<int>(m , 0));

        for(int i = 0 ; i<n ; i++) rowpref[i][0] = new_grid[i][0];
        for(int j = 0 ; j<m ; j++) colpref[0][j] = new_grid[0][j];

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 1 ; j<m ; j++)
            {
                rowpref[i][j] = rowpref[i][j-1] + new_grid[i][j];
            }
        }

        for(int j = 0 ; j<m ; j++)
        {
            for(int i = 1 ; i<n ; i++)
            {
                colpref[i][j] = colpref[i-1][j] + new_grid[i][j];
            }
        }

        int ans = 0;

        for(int k = 0 ; k < n; k++)
        {
            if(k == 0) continue;
            if(new_grid[0][0] != 0 and colpref[k][0] == 0) ans++;
        }
        for(int k = 0 ; k < m; k++)
        {
            if(k == 0) continue;
            if(new_grid[0][0] != 0 and rowpref[0][k] == 0) ans++;
        }
        return ans;
    }
};