// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
       int rows = matrix.size();
       int cols = matrix[0].size();

       int top =0;
       int left = 0;
       int bottom = rows-1;
       int right = cols-1;

       int total_elements = rows * cols;
       int count = 0;

       while(count < total_elements){
        for(int i=left ; i<=right && count <total_elements ; i++){
            ans.push_back(matrix[top][i]);
            count ++;
        }
        top++;

        for(int i=top ; i<=bottom && count <total_elements ; i++){
            ans.push_back(matrix[i][right]);
            count ++;
        }
        right --;

        for(int i=right ; i>=left && count <total_elements ; i--){
            ans.push_back(matrix[bottom][i]);
            count ++;
        }
        bottom--;

         for(int i=bottom ; i>=top && count <total_elements ; i--){
            ans.push_back(matrix[i][left]);
            count ++;
        }
        left++;
       }
       return ans; 
    }
};