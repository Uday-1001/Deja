// https://leetcode.com/problems/equal-sum-grid-partition-i

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        bool ans = false;
        int totalsum = 0;

        vector<vector<int>>rowpref(n , vector<int>(m , 0));
        vector<vector<int>>colpref(n , vector<int>(m , 0));

        for(auto it : grid) for(auto x : it) totalsum += x;

        for(int i = 0 ; i<n ; i++) rowpref[i][0] = grid[i][0];
        for(int j = 0 ; j<m ; j++) colpref[0][j] = grid[0][j];

        for(int j = 1 ; j<m ; j++)
        {
            for(int i = 0 ; i<n ; i++) rowpref[i][j] = rowpref[i][j-1] + grid[i][j];
        }

        for(int i = 1 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++) colpref[i][j] = colpref[i-1][j] + grid[i][j];
        }

        int upsum = 0;
        for(int i = 0 ; i<n ; i++)
        {
            int downsum = totalsum - upsum;
            if(downsum == upsum) 
            {
                ans = true;
                break;
            }
            upsum += rowpref[i][m-1];
        }

        int leftsum = 0;
        for(int j = 0 ; j<m ; j++)
        {
            int rightsum = totalsum - leftsum;
            if(rightsum == leftsum) 
            {
                ans = true;
                break;
            }
            leftsum += colpref[n-1][j];
        }

        return ans;
    }
};