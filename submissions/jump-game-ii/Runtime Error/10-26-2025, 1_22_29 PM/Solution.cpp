// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int mini = INT_MAX;

    int solve(vector<int>&nums , int i , int step_count , vector<vector<int>>&dp)
    {
        if(i == nums.size()-1)
        {
            mini = min(mini, step_count);
            return mini;
        }
        if(i >= nums.size()) return 0;
        if(dp[i][step_count] != -1) return dp[i][step_count];
        
        for(int jumping =1 ; jumping <= nums[i] ; jumping++)  
        {
            int ans = solve(nums, i + jumping , step_count + 1 , dp);
            dp[i][step_count] = ans;
        }
        return dp[i][step_count] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(1001 , -1));

        int ans = solve(nums , 0 , 0 , dp);
        return ans ;
    }
};