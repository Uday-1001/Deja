// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int>& nums, int i)
    {
        if(i >= nums.size() - 1) return true;

        for(int jump = 1 ; jump <= nums[i] ; jump++)
        {
            if(solve(nums, i + jump))
            {
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return solve(nums , 0);
    }
};