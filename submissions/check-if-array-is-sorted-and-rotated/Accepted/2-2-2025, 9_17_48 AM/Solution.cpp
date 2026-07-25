// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rotation = 0;
        for(int i =1 ;i<n ; i++)
        {
            if( nums[i-1] > nums[i])
            {
                rotation++;
            }
        }
        if(nums[n-1] > nums[0]) rotation++;

        return (rotation <=1);
    }
};