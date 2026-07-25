// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
    set<int> unique_nums(nums.begin(), nums.end());
    int index = 0;
    for (int num : unique_nums) {
        nums[index++] = num;
    }
    return unique_nums.size();
}
};