// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int mid = 0; 
        int r = nums.size()-1;

        while(mid <= r)
        {
            if(nums[mid] == 0) swap(nums[mid++] , nums[l++]);
            else if(nums[mid] == 1) mid++;
            else swap(nums[mid] , nums[r--]);
        }
    }
};