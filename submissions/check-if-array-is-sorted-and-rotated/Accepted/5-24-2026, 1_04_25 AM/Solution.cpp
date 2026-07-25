// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int rotation = 0;
        for(int i =0 ; i+1<nums.size() ; i++)
        {
            if(nums[i] > nums[i+1]) rotation++;
        }
        if(nums[nums.size()-1] > nums[0]) rotation++;

        return (rotation <=1);
    }
};