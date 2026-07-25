// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_len = 1;
        int dec_len = 1;

        for(int i=0 ; i<nums.size(); i++)
        {
            if(i+1 < nums.size() && nums[i] > nums[i+1])
                dec_len += 1;
            else if (i+1 < nums.size() && nums[i] == nums[i+1])
                continue;
            else
                break;   
        }
        for(int i=0 ; i<nums.size(); i++)
        {
            if(i+1 < nums.size() && nums[i] < nums[i+1])
                inc_len += 1; 
            else if (i+1 < nums.size() && nums[i] == nums[i+1])
                continue;
            else
                break;  
        }
    return (max(inc_len, dec_len));
    }
};