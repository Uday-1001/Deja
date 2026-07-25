// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0];
        int curr_sum = nums[0];
        
        if(nums.size() == 1) return nums[0];

        for(int i= 1; i<nums.size() ;i++)
        {
            if(nums[i-1] < nums[i])
                curr_sum += nums[i];
            else
                curr_sum = nums[i];
            
            max_sum = max(max_sum , curr_sum);
        }
        return max_sum;
    }
};