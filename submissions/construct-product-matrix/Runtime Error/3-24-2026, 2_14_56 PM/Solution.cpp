// https://leetcode.com/problems/construct-product-matrix

class Solution {
public:
    using ll = long long;
    int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n , vector<int>(m , 0));

        ll prod = 1;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                prod *= grid[i][j];
            }
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                ans[i][j] = (prod / grid[i][j]) % mod;
            }
        }
        return ans;
    }
};