// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    int max_i = 0;
    int maxDiff = 0;
    long long final =0;
    
    for(int k = 0 ; k<nums.size() ; k++)
    {
        final = max(final , (long long)maxDiff * nums[k]);
        maxDiff = max(maxDiff , max_i - nums[k]);
        max_i = max(max_i , nums[k]);
    }

    return final;
    }
};