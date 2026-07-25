// https://leetcode.com/problems/minimum-path-sum

class Solution {
public: 
    int mini = INT_MAX;

    int byrec(vector<vector<int>>& grid , int i, int j , int sum)
    {
        int n = grid.size();
        int m = grid[0].size();
        //base case 
        if(i == n-1 and j == m-1)
        {
            sum = sum + grid[i][j];
            mini = min(mini , sum);
            return mini;
        }

        //ek case hum solve karenge
        //go right
        int right = 0;
        if(j+1 < m)
        {
            right = byrec(grid , i , j+1 , sum + grid[i][j]);
        }

        //go down
        int down = 0;
        if(i+1 < n)
        {
            down = byrec(grid , i+1 , j , sum + grid[i][j]);
        }

        return min(right , down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        byrec(grid , 0 , 0 , 0);
        return mini;
    }
};