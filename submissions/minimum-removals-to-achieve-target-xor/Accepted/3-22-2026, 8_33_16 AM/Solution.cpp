// https://leetcode.com/problems/minimum-removals-to-achieve-target-xor

class Solution {
public:
    int dp[45][20000];
    int byrec(vector<int>&nums , int target , int ans , int i)
    {
        if(i >= nums.size())
        {
            if(ans == target) return 0;
            return -100000;
        }

        if(dp[i][ans] != -1) return dp[i][ans];

        int take = 1 + byrec(nums , target , ans ^ nums[i] , i+1);
        int not_take = 0 + byrec(nums , target , ans , i+1);

        return dp[i][ans] = max(take , not_take);
    }
    
    int minRemovals(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));
        int opr = byrec(nums , target , 0 , 0);

        if(opr < 0) return -1;

        return nums.size() - opr;
    }
};