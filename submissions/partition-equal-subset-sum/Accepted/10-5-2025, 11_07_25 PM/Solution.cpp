// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    int dp[10001][201];

    bool solve(vector<int>&nums , int target , int index)
    {
        //base case 
        if(index >= nums.size() || target < 0) return false;
        if(target == 0) return true;

        if(dp[target][index] != -1) return dp[target][index];

        //we will solve one case only 
        bool include = solve(nums , target - nums[index] , index+1);
        bool exclude = solve(nums , target , index+1);

        return dp[target][index] = include||exclude;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));

        int sum = accumulate(begin(nums) , end(nums) , 0);
        int target = sum / 2;

        if(sum & 1) return false;

        return solve(nums , target , 0);
    }
};