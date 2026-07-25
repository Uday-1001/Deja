// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n * m;
        
        int i = 0;
        int j = m-1;
        while(i < n && j >= 0)
        {
            int elem = matrix[i][j];
            if(elem == target) return true;

            if(elem > target)
            {
                j--;
            }
            else if(elem < target)
            {
                i++;
            }
        }
    return false;
    }
};