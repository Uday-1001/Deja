// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int solve(vector<int>&nums , int i , int step_count , vector<vector<int>>&dp)
    {
        if(i == nums.size()-1) return step_count;
        if(i >= nums.size()) return INT_MAX;

        if(dp[i][step_count] != -1) return dp[i][step_count];
        
        int mini = INT_MAX;
        for(int jumping =1 ; jumping <= nums[i] ; jumping++)  
        {
            int ans = solve(nums , (i + jumping) , (step_count + 1) , dp);
            mini = min(mini , ans);
        }
        return dp[i][step_count] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1, -1));

        return solve(nums , 0 , 0 , dp);
    }
};