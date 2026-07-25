// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
            if(i==j && n-j-1==i){
                 sum=sum+mat[i][j];}
            else if(i==j){
                 sum=sum+mat[i][j];}
            else if(i==n-j-1){
                 sum=sum+mat[i][j];
            }
        }
     }
        return sum;


    }
};