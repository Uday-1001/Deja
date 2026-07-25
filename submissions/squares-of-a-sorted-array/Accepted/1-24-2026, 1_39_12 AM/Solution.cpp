// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size() , 0);
        int l = 0 , r = nums.size()-1;

        for(int i = nums.size()- 1; i>= 0 ; i--)
        {
            if(abs(nums[l]) > abs(nums[r]))
            {
                ans[i] = nums[l] * nums[l];
                l++;
            }
            else 
            {
                ans[i] = nums[r] * nums[r];
                r--;
            }
        }
    return ans;
    }
};