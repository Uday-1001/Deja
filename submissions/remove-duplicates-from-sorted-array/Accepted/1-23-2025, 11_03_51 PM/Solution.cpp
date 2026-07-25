// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
    // Method 1 :- set method

    // set<int> unique_nums(nums.begin(), nums.end());
    // int index = 0;
    // for (int num : unique_nums) {
    //     nums[index++] = num;
    // }
    // return unique_nums.size();
    
    // Method 2 :- slow and fast pointers

    if (nums.empty()) return 0;
    
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
};