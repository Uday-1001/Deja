// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int len = INT_MAX , sum = 0;

        for(int r = 0 ; r<n ; r++)
        {
            sum += nums[r];
            while(sum >= target)
            {
                len = min(len , r-l+1);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};