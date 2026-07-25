// https://leetcode.com/problems/house-robber

class Solution {
public:
    int dp[101];

    int solve(vector<int>&nums , int index)
    {
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];

        //we will solve one case only
        int rob_house = nums[index] + solve(nums , index+2);
        int leave_house_and_rob_next = solve(nums , index+1);

        return dp[index] = max(rob_house , leave_house_and_rob_next);
    }

    int rob(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0);
    }
};