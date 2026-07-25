// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l {};
        int mid {}; 
        int r {n-1};

        while(mid <= r)
        {
            if(nums[mid] == 0) swap(nums[mid++] , nums[l++]);
            else if(nums[mid] == 1) mid++;
            else swap(nums[mid] , nums[r--]);
        }
    }
};