// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = INT_MIN;
        int sum1 = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum1 += nums[i]; 
            ans1 = max(ans1 , sum1);
            if(sum1 < 0) sum1 = 0; 
        }
        int sum = 0;
        int ans2 = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            sum += nums[i]; 
            ans2 = min(ans2 , sum);
            if(sum > 0) sum = 0; 
        }
        return max(abs(ans1) , abs(ans2));  
    }
};