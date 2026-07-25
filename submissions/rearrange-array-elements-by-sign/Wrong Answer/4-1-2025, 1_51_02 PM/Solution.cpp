// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
    int pos = 0, neg = 1; // Position for next positive and negative numbers

    while (pos < n && neg < n) {
        // Find misplaced positive at even index
        while (pos < n && nums[pos] > 0) pos += 2;
        
        // Find misplaced negative at odd index
        while (neg < n && nums[neg] < 0) neg += 2;

        // Swap if within bounds
        if (pos < n && neg < n) {
            swap(nums[pos], nums[neg]);
        }
    }
    return nums;   
    }
};