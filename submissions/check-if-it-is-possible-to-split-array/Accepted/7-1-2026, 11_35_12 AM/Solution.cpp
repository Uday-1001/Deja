// https://leetcode.com/problems/check-if-it-is-possible-to-split-array

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n <= 2) return true;

        for(int i = 1 ; i<n ; i++) if(nums[i-1] + nums[i] >= m) return true;
        return false;
    }
};