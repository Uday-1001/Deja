// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

class Solution {
public:
    void makeprefixes(vector<vector<int>>&rp , vector<vector<int>>& grid)
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
    }

    bool isValid(int n , int m , int i , int j , int size , vector<vector<int>>&rp , vector<vector<int>>& grid , int threshold)
    {
        int rowsum = rp[i][j+size] - rp[i][j];
        for(int k = 1 ; k<size ; k++)
        {
            int sum = rp[i+k][j+size] - rp[i+k][j];
            if(sum > threshold) return false;
        }
        return true;
    }

    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        int n = grid.size();
        int m = grid[0].size();
        int maxsize = 0;

        vector<vector<int>>rp(n , vector<int>(m+1 ,0));

        for(int i = 0 ; i<m ; i++) rp[0][i] = 0;

        makeprefixes(rp , grid);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                int possible_squares = min(n - i , m - j);

                for(int size = 2 ; size <= possible_squares ; size++)
                {
                    if(isValid(n , m , i , j , size , rp , grid , threshold)) 
                    {
                        maxsize = max(maxsize , size);
                    }
                }
            }
        }
    return maxsize;
    }
};