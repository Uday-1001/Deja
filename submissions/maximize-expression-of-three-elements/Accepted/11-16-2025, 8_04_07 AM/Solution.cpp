// https://leetcode.com/problems/maximize-expression-of-three-elements

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        reverse(nums.begin() , nums.end());
        return (nums[0] + nums[1]) - nums[nums.size()-1];
    }
};