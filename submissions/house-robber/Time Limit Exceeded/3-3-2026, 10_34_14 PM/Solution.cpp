// https://leetcode.com/problems/house-robber

class Solution {
public:
    int byrec(vector<int>&nums , int i)
    {
        if(i >= nums.size()) return 0;

        int include = nums[i] + byrec(nums , i+2);
        int exclude = 0 + byrec(nums , i+1);

        return max(include , exclude);
    }

    int rob(vector<int>& nums) {
        return byrec(nums , 0);
    }
};