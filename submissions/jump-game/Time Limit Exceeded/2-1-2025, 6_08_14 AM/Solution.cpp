// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int>&nums ,int i)
    {
        if(i >= nums.size()-1) return true;
        if(nums[i] == 0) return false;
        
        int jump = nums[i];
        bool reAns = false;
        for(int step =1 ; step <= jump ; step++)
        {   
            reAns = reAns || solve(nums, i + step);
        }
        return reAns;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums , 0);
    }
};