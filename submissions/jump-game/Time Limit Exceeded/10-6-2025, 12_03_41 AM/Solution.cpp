// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int>&nums , int i)
    {
        //base case
        if(i == nums.size()-1) return true;
        if(i >= nums.size()) return false;

        //we will solve only one case 
        bool ans = false;
        for(int jump=1 ; jump<=nums[i] ; jump++)
        {
            ans = ans || solve(nums , i+jump);
        }
        return ans;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums , 0);
    }
};