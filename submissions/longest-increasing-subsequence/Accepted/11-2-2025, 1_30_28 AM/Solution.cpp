// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int bymem(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        //base case
        if(curr >= nums.size()) return 0;
        
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        //ek case hum solve karenge
        int include = 0; 
        if(prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + bymem(nums, curr+1 , curr, dp);
        }
        int exclude = 0 + bymem(nums, curr+1 , prev, dp);

        return dp[curr][prev+1] = max(include , exclude);
    }

    int byrec(vector<int>& nums, int curr, int prev){
        //base case
        if(curr >= nums.size()) return 0;
        
        //ek case hum solve karenge
        int include = 0; 
        if(prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + byrec(nums, curr+1 , curr);
        }
        int exclude = 0 + byrec(nums, curr+1 , prev);

        return max(include , exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        //return byrec(nums, 0, -1);
        
        int n = nums.size();
        vector<vector<int>>dp (n+1,vector<int>(n+1, -1));
        return bymem(nums, 0, -1, dp);
    }
};