// https://leetcode.com/problems/largest-magic-square

class Solution {
public:
    void makeprefixes(vector<vector<int>>&rp , vector<vector<int>>&cp , vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 1 ; j<=m ; j++)
            {
                rp[i][j] = rp[i][j-1] + grid[i][j-1];
            }
        }
        for(int j = 0; j < m; j++)
        {
            for(int i = 1; i <= n; i++)
            {
                cp[i][j] = cp[i-1][j] + grid[i-1][j];
            }
        }
    }

    bool isValidInAllWays(int n , int m , int i , int j , int size , vector<vector<int>>&rp , vector<vector<int>>&cp , vector<vector<int>>& grid)
    {
        //row sum checking
        int rowsum = rp[i][j+ size] - rp[i][j];
        for(int k = 1 ; k<size ; k++)
        {
            int sum = rp[i+k][j+size] - rp[i+k][j];
            if(sum != rowsum) return false;
        }
        //col sum checking
        int colsum = cp[i+size][j] - cp[i][j];
        for(int k = 1 ; k<size ; k++)
        {
            int sum = cp[i+size][j+k] - cp[i][j+k];
            if(sum != colsum) return false;
        }
        // main diagonal
        int main_diagonal = 0;
        for(int k = 0; k < size; k++)
        {
            main_diagonal += grid[i + k][j + k];
        }
        if(main_diagonal != rowsum) return false;

        // anti diagonal
        int anti_diagonal = 0;
        for(int k = 0; k < size; k++)
        {
            anti_diagonal += grid[i + k][j + (size - 1 - k)];
        }
        if(anti_diagonal != rowsum) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxsize = 1;

        vector<vector<int>>rp(n , vector<int>(m+1 ,0));
        vector<vector<int>>cp(n+1 , vector<int>(m , 0));

        for(int i = 0 ; i<m ; i++) rp[0][i] = 0;
        for(int i = 0 ; i<n ; i++) cp[i][0] = 0;

        makeprefixes(rp , cp , grid);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                int possible_squares = min(n - i , m - j);

                for(int size = 2 ; size <= possible_squares ; size++)
                {
                    if(isValidInAllWays(n , m , i , j , size , rp , cp , grid)) 
                    {
                        maxsize = max(maxsize , size);
                    }
                }
            }
        }
    return maxsize;
    }
};