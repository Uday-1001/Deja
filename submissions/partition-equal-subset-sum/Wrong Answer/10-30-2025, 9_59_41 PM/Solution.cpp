// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool bymemo(vector<int>&nums , int target , int i , vector<vector<bool>>&dp)
    {
        if(target == 0) return true;
        if(i >= nums.size() or target < 0) return false;
        if(dp[target][i] != -1) return dp[target][i];

        int include = bymemo(nums , target-nums[i] , i+1 , dp);
        int exclude = bymemo(nums , target , i+1 , dp);

        return dp[target][i] = include || exclude;
    }

    // bool byrec(vector<int>&nums , int target , int i)
    // {
    //     //base case 
    //     if(target == 0) return true;
    //     if(i >= nums.size() or target < 0) return false;

    //     int include = byrec(nums , target-nums[i] , i+1);
    //     int exclude = byrec(nums , target , i+1);

    //     return include || exclude;
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums) , end(nums) , 0);

        if(sum & 1) return false;
        int target = sum / 2;

        // return byrec(nums , target , 0);

        vector<vector<bool>>dp(target+1 , vector<bool>(n+1 , -1));
        return bymemo(nums , target , 0 , dp);
    }
};