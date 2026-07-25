// https://leetcode.com/problems/left-and-right-sum-differences

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right = accumulate(begin(nums) , end(nums) , 0);
        int left = 0;

        vector<int>ans;
        for(auto it : nums)
        {
            ans.push_back(abs(right - left - it));
            right -= it;
            left += it;
        }
        return ans;
    }
};