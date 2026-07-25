// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int KadaneAlgo(vector<int>&nums)
    {
        int sum = 0;
        int ans = INT_MIN;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            sum += nums[i];
            ans = max(ans , sum);

            if(sum < 0) sum = 0;
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        return KadaneAlgo(nums);
    }
};