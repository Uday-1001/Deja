// https://leetcode.com/problems/binary-subarrays-with-sum

class Solution {
public:
    int solve(vector<int>&nums , int goal)
    {
        int l = 0 , r = 0 , sum = 0;
        int count = 0;

        if(goal < 0) return 0;

        for(int r=0 ; r<nums.size() ; r++)
        {
            sum += nums[r];
            
            while(sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
        }
    return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums , goal) - solve(nums , goal-1);
    }
};