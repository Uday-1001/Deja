// https://leetcode.com/problems/special-array-i

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;

        for(int i = 0; i<nums.size() ;i++)
        {
            if((i+1) < nums.size() && (nums[i] & 1) && (nums[i+1] & 1))
            return false;
        }
        return true;
    }
};