// https://leetcode.com/problems/jump-game

class Solution {
public:
    int solve(vector<int>&nums, int i)
    {
        if(i >= nums.size()) return false;
        if(i == nums.size()-1) return true;

        for(int jump = 1 ; jump <= nums[i] ; i++)
        {
            int nextjumpindex = i + jump;
            bool recursiveAns = solve(nums , nextjumpindex);
            if(recursiveAns) return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        return solve(nums , 0);
    }
};