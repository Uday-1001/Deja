// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<=end)
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] < target)
            {
                start = ++mid;
            }
            else{
                end = --mid;
            }
        }
        return start;
    }
};