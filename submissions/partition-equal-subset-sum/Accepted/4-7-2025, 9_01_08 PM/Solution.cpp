// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool bydp(vector<int>& nums , int i , int target_sum , vector<vector<int>>&dp)
    {
        //base case
        if(target_sum == 0) 
        {
            return true;
        }
        if(i >=nums.size() or target_sum < 0) return false;
        
        if(dp[i][target_sum] != -1)
        {
            return dp[i][target_sum];
        }

        //ek case hum solve krenge baaki recursion dekhlega
        //include 
        bool include = bydp(nums , i+1 , target_sum - nums[i] , dp);

        //exclude
        bool exclude = bydp(nums , i+1 , target_sum , dp);

        dp[i][target_sum] = include or exclude;
        return dp[i][target_sum];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(sum & 1) return false;

        int target_sum = sum / 2;

        vector<vector<int>>dp(n+1,vector<int>(target_sum+1,-1));
        return bydp(nums,0,target_sum , dp);
    }
};