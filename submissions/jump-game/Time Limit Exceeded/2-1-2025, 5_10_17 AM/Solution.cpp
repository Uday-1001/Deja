// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int>& nums, int i) {
        if (i >= nums.size() - 1) return true; // If we reach or go beyond the last index, return true
        if (nums[i] == 0) return false;        // If stuck at 0, return false

        int maxJump = nums[i]; // Maximum steps we can take from this index

        for (int step = 1; step <= maxJump; step++) {
            if (solve(nums, i + step)) return true; // If any path leads to success, return true
        }

        return false; // If no valid path, return false
    }

    bool canJump(vector<int>& nums) {
        return solve(nums , 0);
    }
};