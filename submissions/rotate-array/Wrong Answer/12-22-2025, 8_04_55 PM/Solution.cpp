// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 2)
        {
            if(k & 1) swap(nums[0] , nums[1]);
        }

        if(nums.size() > k)
        {
            reverse(nums.begin() , nums.end());
            reverse(nums.begin() , nums.begin() + k);
            reverse(nums.begin() + k , nums.end());
        }
    }
};