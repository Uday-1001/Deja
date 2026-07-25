// https://leetcode.com/problems/find-the-degree-of-each-vertex

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans(matrix.size() , 0);
        for(int j = 0 ; j<matrix[0].size() ; j++)
        {
            for(int i = 0 ; i<matrix.size() ; i++)
            {
                if(i == j) continue;
                else ans[j] += matrix[i][j];
            }
        }
        return ans;
    }
};