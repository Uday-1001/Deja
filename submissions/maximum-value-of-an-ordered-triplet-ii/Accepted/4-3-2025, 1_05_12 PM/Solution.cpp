// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int max_i = 0;
        long long result = 0;
        int maxDiff = 0;

        for(int j =0 ; j<nums.size() ; j++)
        {
            result = max(result , (long long)maxDiff * nums[j]);
            maxDiff = max(maxDiff , max_i - nums[j]);
            max_i = max(max_i , nums[j]);
        }
        return result;
    }
};