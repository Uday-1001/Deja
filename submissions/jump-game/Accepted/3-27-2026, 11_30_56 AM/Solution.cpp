// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp)
    {
        if(i == nums.size() - 1) return true;
        if(i >= nums.size()) return false;

        if(dp[i] != -1) return dp[i];

        if(nums[i] == 0) return dp[i] = false;

        for(int jump = 1 ; jump <= nums[i] ; jump++)
        {
            if(solve(nums, i + jump, dp))
            {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , -1);
        return solve(nums , 0 , dp);
    }
};