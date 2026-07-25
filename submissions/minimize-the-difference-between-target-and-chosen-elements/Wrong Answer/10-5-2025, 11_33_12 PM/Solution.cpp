// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int solve(vector<vector<int>>& mat, int target , int sum , int row , int &ans)
    {
        //base case 
        if(row >= mat.size())
        {
            ans = min(ans , abs(target - sum));
            return ans;
        }

        //we will dolve one case only 
        for(int col = 0 ; col<mat[row].size() ; col++)
        {
            int choice = solve(mat , target , sum + mat[row][col] , row + 1 , ans);
            int reject_choice = solve(mat , target , sum , row + 1 , ans); 
        }
        return ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int ans = INT_MAX;

        solve(mat , target , 0 , 0 , ans);
        return ans;
    }
};