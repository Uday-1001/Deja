// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos_index = 0;
        int neg_index = 1;

        while(pos_index < n && neg_index < n)
        {
            while(pos_index < n && nums[pos_index] > 0)
            pos_index += 2;

            while(neg_index < n && nums[neg_index] < 0)
            neg_index += 2;

            if(pos_index < n && neg_index < n)
            {
                swap(nums[pos_index] , nums[neg_index]);
            }
        }
    return nums;   
    }
};