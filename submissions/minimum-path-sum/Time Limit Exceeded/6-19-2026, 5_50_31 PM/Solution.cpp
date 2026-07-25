// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int n , m;
    int mini = INT_MAX;

    void solve(vector<vector<int>>& grid , int i , int j , int sum) 
    {
        if(i >= n or j >= m) return;

        if(i == n-1 and j == m-1)
        {
            mini = min(mini , sum + grid[i][j]);
            return;
        }

        solve(grid , i+1 , j , sum + grid[i][j]);
        solve(grid , i , j+1 , sum + grid[i][j]);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        solve(grid , 0 , 0 , 0);
        return mini;
    }
};