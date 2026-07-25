// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>flattened;
        for(int i = 0 ; i<n ; i++) for(int j = 0 ; j<m ; j++) flattened.push_back(matrix[i][j]);

        int s = 0;
        int e = flattened.size()-1;
        
        while(s <= e)
        {
            int mid = s + (e-s) / 2;
            if(flattened[mid] == target) return true;
            else if(flattened[mid] < target) s = mid+1;
            else e = mid-1;
        }
        return false;
    }
};