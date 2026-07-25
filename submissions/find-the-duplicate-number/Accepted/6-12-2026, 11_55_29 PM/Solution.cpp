// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0 ;; i++)
        {
            if(nums[0] == nums[nums[0]]) break;
            swap(nums[0] , nums[nums[0]]);
        }
        return nums[0];
    }
};