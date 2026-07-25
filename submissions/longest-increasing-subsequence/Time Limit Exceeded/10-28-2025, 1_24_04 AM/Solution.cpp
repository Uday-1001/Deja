// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int solve(vector<int>&nums , int& last_num , int i)
    {   
        if(i >= nums.size()) return 0;

        //ek case hum solve karenge
        int ans = INT_MIN;
        int include = 0;
        if(nums[i] > last_num)
        {
            include = 1 + solve(nums , nums[i] , i+1);  
        }
        int exclude = solve(nums , last_num , i+1);
        ans = max(include , exclude);
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int last_num = INT_MIN;
        return solve(nums , last_num , 0);
    }
};