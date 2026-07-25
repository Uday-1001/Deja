// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index

class Solution {
public:
    int byrec(vector<int>&nums , int i , int &target)
    {
        if(i == nums.size()-1) return 0;
        if(i >= nums.size()) return -1;

        int ans = -1;

        for(int j = i+1 ; j<nums.size() ; j++)
        {
            int nextone = nums[j];
            if(nextone - nums[i] >= -target and nextone - nums[i] <= target)
            {
                int nextsteps = 1 + byrec(nums , j , target);
                if(nextsteps != 0) ans = max(ans , nextsteps);
            }
        }
        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int ans = byrec(nums , 0 , target);
        return ans;
    }
};