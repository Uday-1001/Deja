// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i = n-1 , j = 0 , count = 0;

        while(i >= 0 and j < m)
        {
            if(grid[i][j] < 0)
            {
                count += (m - j);
                i--;
            } 
            else j++;
        }
    return count;
    }
};