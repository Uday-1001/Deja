// https://leetcode.com/problems/largest-magic-square

class Solution {
public:
    void makeprefixes(vector<vector<int>>&rp , vector<vector<int>>&cp , vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 1 ; j<m ; j++)
            {
                rp[i][j] = rp[i][j-1] + grid[i][j-1];
            }
        }
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                cout<<rp[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>>rp(n+1 , 0) , cp(m+1 , 0);

        for(int i = 0 ; i<m ; i++) rp[0][i] = 0;
        for(int i = 0 ; i<n ; i++) cp[i][0] = 0;

        makeprefixes(rp , cp , grid);
        return 0;

    }
};