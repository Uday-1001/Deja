// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int solve(vector<int>&nums , int i , int &len)
    {   
        if(i >= nums.size()) return 0;

        //ek case hum solve karenge
        int ans = INT_MIN;
        if(nums[i] > nums[i-1])
        {
            len++;
            int include = 1 + solve(nums , i+1 , len);
            ans = max(ans , include);
        }
        else
        {
            int exclude = solve(nums , i+1 , len);
            ans = max(ans , exclude);
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        solve(nums , 1 , len);
        return len;
    }
};