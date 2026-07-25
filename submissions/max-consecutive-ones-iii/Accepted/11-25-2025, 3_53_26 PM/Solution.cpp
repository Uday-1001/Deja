// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int max_freq = 0;
        int maxlen = 0;
        vector<int>hash(2 , 0);

        for(int r = 0 ; r<nums.size() ; r++)
        {
            hash[nums[r]]++;
            if(nums[r] == 1) max_freq = max(max_freq , hash[nums[r]]);
            int flipping = (r-l+1) - max_freq;

            if(flipping > k)
            {
                hash[nums[l]]--;
                l++;
            }
            if(flipping <= k)
            {
                maxlen = max(maxlen , r-l+1);
            }
        }
    return maxlen;
    }
};