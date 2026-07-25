// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix=0;
        int minsum=INT_MAX;
        int maxsum = INT_MIN;
        int ans=0;
        for(auto num:nums)
        {
            prefix +=num;
            minsum=min(prefix,minsum);
            maxsum = max(prefix, maxsum);
            ans = max(maxsum-minsum, ans);
        }
        return ans;
    }
};