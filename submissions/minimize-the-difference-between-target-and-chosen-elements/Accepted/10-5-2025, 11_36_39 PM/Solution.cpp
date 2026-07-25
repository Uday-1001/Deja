// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int dp[4901][71];

    int solve(vector<vector<int>>& mat, int target , int sum , int row , int &ans)
    {
        //base case 
        if(row >= mat.size())
        {
            ans = min(ans , abs(target - sum));
            return ans;
        }
        if(dp[sum][row] != -1) return dp[sum][row];

        //we will solve one case only 
        for(int col = 0 ; col<mat[row].size() ; col++)
        {
            int choice = solve(mat , target , sum + mat[row][col] , row + 1 , ans);
        }
        return dp[sum][row] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp , -1 , sizeof(dp));
        int ans = INT_MAX;

        solve(mat , target , 0 , 0 , ans);
        return ans;
    }
};