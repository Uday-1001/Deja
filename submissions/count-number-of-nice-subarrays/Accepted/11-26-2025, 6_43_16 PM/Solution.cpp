// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int solve(vector<int>&nums , int k)
    {
        if(k < 0) return 0;
        int l = 0;
        int sum = 0;
        int subarrays = 0;

        for(int r=0 ; r<nums.size() ; r++)
        {
            sum += nums[r] % 2;

            while(sum > k)
            {
                sum -= nums[l] % 2;
                l++;
            }
            subarrays += (r-l+1);
        }
    return subarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &num : nums)
        {
            if(num & 1) num = 1;
            else num = 0;
        }
        return solve(nums , k) - solve(nums , k-1);
    }
};