// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            int sum = 0;
            for(int j = i ; j<nums.size() ; j++)
            {
                sum += nums[j]; 
                ans = max(ans , abs(sum)); 
            }
        }
        return ans;    
    }
};