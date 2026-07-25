// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int>&nums , int i , vector<int>&dp)
    {
        //base case
        if(i == nums.size()-1) return true;
        if(i >= nums.size()) return false;
        if(nums[i] == 0) return false;

        if(dp[i] != -1) return dp[i];

        //we will solve only one case 
        bool ans = false;
        for(int jump=1 ; jump<=nums[i] ; jump++)
        {
            ans = ans || solve(nums , i+jump , dp);
        }
        return dp[i] = ans;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , -1);
        return solve(nums , 0 , dp);
    }
};