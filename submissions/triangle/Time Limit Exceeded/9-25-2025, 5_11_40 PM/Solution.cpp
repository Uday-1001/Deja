// https://leetcode.com/problems/triangle

class Solution {
public:
    void solve (vector<vector<int>>& triangle ,int row , int col , int path_sum , int &mini)
    {
        if(row == triangle.size()){
            mini = min(mini , path_sum);
            return;
        }
    
        solve(triangle , row+1 , col+1 , path_sum + triangle[row][col], mini);
        solve(triangle , row+1 , col , path_sum + triangle[row][col], mini);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int mini = INT_MAX;
        solve(triangle, 0 , 0 , 0 , mini);
        return mini;
    }
};