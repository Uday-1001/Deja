// https://leetcode.com/problems/triangle

class Solution {
public:
    void solve(vector<vector<int>>& triangle , int row ,int col , int &ans , int path_sum)
    {
        if(row == triangle.size()-1) 
        {
            ans = min(ans , path_sum + triangle[row][col]);
            return;
        }
        if(row >= triangle.size()) return;

        solve(triangle , row+1 , col, ans , path_sum + triangle[row][col]);

        solve(triangle , row+1 , col+1 , ans , path_sum + triangle[row][col]);
    
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        solve(triangle, 0 , 0 , ans , 0);
        return ans;
    }
};