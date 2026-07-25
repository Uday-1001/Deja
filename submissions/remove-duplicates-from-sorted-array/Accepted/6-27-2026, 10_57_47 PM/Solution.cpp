// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(begin(nums) , end(nums)) , end(nums));
        return nums.size();
    }
};