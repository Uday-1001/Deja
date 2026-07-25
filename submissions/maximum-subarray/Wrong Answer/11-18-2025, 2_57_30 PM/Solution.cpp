// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = -1;
        //single element 
        if(nums.size() == 1) return nums[0];

        for(int i=0 ; i<nums.size() ; i++)
        {
            sum += nums[i];
            ans = max(sum , ans);

            if(sum < 0) sum = 0;
        }
    return ans;
    }
};