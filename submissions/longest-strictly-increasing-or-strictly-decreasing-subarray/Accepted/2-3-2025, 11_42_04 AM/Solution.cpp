// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_len = 1, max_inc = 1;
        int dec_len = 1, max_dec = 1;

        for(int i=0 ; i<nums.size(); i++)
        {
            if(i+1 < nums.size() && nums[i] > nums[i+1])
            {
                inc_len++;
                dec_len = 1;
            }
            else if(i+1 < nums.size() && nums[i] < nums[i+1])
            {
                dec_len++;
                inc_len = 1;
            }
            else
            {
                dec_len = 1;
                inc_len = 1;
            }
            max_inc = max(max_inc , inc_len);
            max_dec = max(max_dec , dec_len);
        }    
    return (max(max_inc, max_dec));
    }
};