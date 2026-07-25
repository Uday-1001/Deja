// https://leetcode.com/problems/find-a-peak-element-ii

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int s = 0;
        int e = m-1;

        while(s<=e)
        {
            int mid_col = s+(e-s)/2;
            //to store the row number of the peak element 
            int row_peak_pt = 0;

            for(int row = 0 ; row<n ; row++)
            {
                if(mat[row][mid_col] > mat[row_peak_pt][mid_col])
                {
                    row_peak_pt = row;
                }
            }
            //get the left and right neighbour
            int left_one = mid_col > 0 ? mat[row_peak_pt][mid_col-1] : -1;
            int right_one = mid_col > m-1 ? mat[row_peak_pt][mid_col+1] : -1;

            //check whether our selection is greater than left and right -> for peak element
            if(mat[row_peak_pt][mid_col] > left_one && mat[row_peak_pt][mid_col] > right_one)
            {
                return {row_peak_pt , mid_col};
            }
            else if(mat[row_peak_pt][mid_col] < left_one)
            {
                s = mid_col - 1;
            }
            else
            {
                e = mid_col + 1;
            }
        }
    return {-1,-1};
    }
};