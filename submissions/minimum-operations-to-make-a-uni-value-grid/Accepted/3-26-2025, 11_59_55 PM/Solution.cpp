// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        //storing the elements in an array;
        vector<int>nums;
        for(int i= 0 ; i<grid.size() ; i++)
        {
            for(int j =0 ; j<grid[0].size(); j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin() , nums.end());

        int size = nums.size();
        int median = nums[size/2];
        int count_opr = 0;

        for(int i=0; i<size ; i++)
        {
            int difference = abs(median - nums[i]);
            //difference must be a whole no. so as to be made upto the median element.
            if(difference % x != 0)
            {
                return -1;
            }
            count_opr += difference / x;
        }
    return count_opr;
    }
};