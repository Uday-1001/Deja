// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    void solve(vector<int>&nums , int i , int &len)
    {   
        if(i >= nums.size()) return;

        //ek case hum solve karenge
        if(nums[i] > nums[i-1])
        {
            len++;
            solve(nums , i+1 , len);
        }
        else
        {
            solve(nums , i+1 , len);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        solve(nums , 1 , len);
        return 1 + len;
    }
};