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
        int rowsum = 0;
        for(int k = 0 ; k<size ; k++)
        {
            rowsum += rp[i+k][j+size] - rp[i+k][j];
            if(rowsum > threshold) return false;
        }
        return rowsum <= threshold;
    }

    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        int n = grid.size();
        int m = grid[0].size();
        int maxsize = 0;

        vector<vector<int>>rp(n , vector<int>(m+1 , 0));

        for(int i = 0 ; i<m ; i++) rp[0][i] = 0;

        makeprefixes(rp , grid);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                int possible_squares = min(n - i , m - j);

                int s = 0 , e = possible_squares;
                int ans = 0;

                while(s <= e)
                {
                    int mid = s + (e-s)/2;
                    if(isValid(n , m , i , j , mid , rp , grid , threshold))
                    {
                        ans = mid;
                        s = mid + 1;
                    }
                    else e = mid - 1;
                }
                maxsize = max(maxsize , ans);
            }
        }
    return maxsize;
    }
};