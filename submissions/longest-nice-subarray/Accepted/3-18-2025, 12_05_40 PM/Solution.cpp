// https://leetcode.com/problems/longest-nice-subarray

class Solution {
public:

    int longestNiceSubarray(vector<int>& nums) {
        int l = 0 ; int r = 0;
        int mask = 0;
        int maxlen = 0;

        while(r<nums.size())
        {
            if((nums[r] & mask) == 0)
            {
                mask = mask | nums[r];
                maxlen = max(maxlen , r-l+1);
                r++;
            }
            else
            {
                mask ^= nums[l];
                l++;   
            }
        }
        return maxlen;
    }
};