// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int solve(vector<int>&nums , int& last_num_index , int i)
    {   
        if(i >= nums.size()) return 0;

        //ek case hum solve karenge
        int include = 0;
        if(last_num_index == -1 or nums[i] > nums[last_num_index])
        {
            include = 1 + solve(nums , i , i+1);  
        }
        int exclude = solve(nums , last_num_index , i+1);
        return max(include , exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int last_num_index = -1;
        return solve(nums , last_num_index , 0);
    }
};