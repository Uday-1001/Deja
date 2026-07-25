// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    void solve(vector<vector<int>>& mat, int &target , int sum , int row , int &mini)
    {
        //base case 
        if(row == mat.size())
        {
           mini = min(mini , abs(target-sum));
           return; 
        }
        //ek case hum solve karenge baaki recursion kardega 
        //traversse each col ,row and pick the element and find the diff
        for(int col= 0 ; col<mat[row].size() ; col++)
        {
            //include the element in the sum
            solve(mat , target , sum + mat[row][col] , row + 1 , mini);
        }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int mini = INT_MAX;
        solve(mat , target , 0 , 0 , mini);
        return mini;
    }
};