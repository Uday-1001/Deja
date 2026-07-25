// https://leetcode.com/problems/jump-game

class Solution {
public:
    int dp[100001];
    bool solve(vector<int>&nums , int i)
    {
        //base case
        if(i == nums.size()-1) return true;
        if(i >= nums.size()) return false;

        if(dp[i] != -1) return dp[i];

        //we will solve only one case 
        bool ans = false;
        for(int jump=1 ; jump<=nums[i] ; jump++)
        {
            ans = ans || solve(nums , i+jump);
        }
        return dp[i] = ans;
    }

    bool canJump(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0);
    }
};