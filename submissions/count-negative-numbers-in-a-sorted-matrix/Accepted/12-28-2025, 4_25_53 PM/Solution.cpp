// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int binarySearch(vector<vector<int>>&grid , int i)
    {
        int s = 0;
        int e = grid[0].size()-1;
        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(grid[i][mid] < 0)
            {
                ans = mid;
                e = mid - 1;
            } 
            else s = mid + 1;
        }
    return ans;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int colsize = grid[0].size();
        for(int i = 0 ; i < grid.size() ; i++)
        {
            int index = binarySearch(grid , i);
            count += (index != -1) ? (colsize - index) : 0;
        }
    return count;
    }
};