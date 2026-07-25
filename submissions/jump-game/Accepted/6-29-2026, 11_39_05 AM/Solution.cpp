// https://leetcode.com/problems/jump-game

class Solution {
public:
    vector<int>dp;

    int solve(vector<int>&nums, int i)
    {
        if(i >= nums.size()) return false;
        if(i == nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];

        for(int jump = 1 ; jump <= nums[i] ; jump++)
        {
            int nextjumpindex = i + jump;
            bool recursiveAns = solve(nums , nextjumpindex);
            if(recursiveAns) return true;
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n+1 , -1);
        if(nums.size() == 1) return true;
        return solve(nums , 0);
    }
};