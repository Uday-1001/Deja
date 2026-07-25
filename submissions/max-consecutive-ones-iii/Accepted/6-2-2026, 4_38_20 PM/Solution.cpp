// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ones = 0;
        int maxlen = 0;

        int l = 0;

        for(int r = 0 ; r<n ; r++)
        {
            if(nums[r] == 1) ones++;
            int len = r - l + 1;
            int flips = len - ones;

            if(flips <= k) maxlen = max(maxlen , len);

            if(flips > k)
            {
                if(nums[l] == 1) ones--;
                l++;
            }
        }
        return maxlen;
    }
};