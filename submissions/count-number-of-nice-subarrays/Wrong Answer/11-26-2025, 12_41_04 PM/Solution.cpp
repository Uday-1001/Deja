// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int solve(vector<int>&nums , int k)
    {
        int l =0;
        int count_odd = 0;
        int other_elements = 0;
        int subarrays = 0;

        for(int r=0 ; r<nums.size() ; r++)
        {
            if(nums[r] & 1) count_odd++;
            else other_elements++;

            if(count_odd > k)
            {
                if(nums[l] & 1) count_odd--;
                l++;
            }
            if(count_odd == k)
            {
                subarrays = other_elements * 2;
            }
        }
    return subarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k);
    }
};