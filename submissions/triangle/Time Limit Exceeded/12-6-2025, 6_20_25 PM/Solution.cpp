// https://leetcode.com/problems/triangle

class Solution {
public:
    int solve(vector<vector<int>>& triangle ,int row , int col)
    {
        if(row == triangle.size()){
            return 0;
        }

        int mini = INT_MAX;
        int op1 = triangle[row][col] + solve(triangle , row+1 , col+1);
        int op2 = triangle[row][col] + solve(triangle , row+1 , col);

        int optimal = min(op1 , op2);
        mini = min(mini , optimal);

        return mini;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0 , 0);
    }
};