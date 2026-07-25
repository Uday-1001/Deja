// https://leetcode.com/problems/final-element-after-subarray-deletions

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(0 , nums[nums.size() - 1]);
    }
};