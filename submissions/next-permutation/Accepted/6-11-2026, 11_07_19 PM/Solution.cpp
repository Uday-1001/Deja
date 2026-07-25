// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {        
        int i = nums.size()-2;
        while(i >= 0 and nums[i] >= nums[i+1]) i--;

        if(i == -1)
        {
            reverse(begin(nums) , end(nums));
            return;
        }

        int j = nums.size()-1;
        while(j >= 0 and nums[j] <= nums[i]) j--;

        swap(nums[i] , nums[j]);

        reverse(nums.begin() + (i+1) , nums.end());
    }
};