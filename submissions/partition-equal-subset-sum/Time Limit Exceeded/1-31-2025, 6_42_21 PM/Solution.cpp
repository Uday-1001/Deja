// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool solve(vector<int>& nums,int targetSum , int index)
    {
        if(targetSum == 0) return true;
        if(index >= nums.size() || targetSum < 0) return false;

        bool include = solve(nums, targetSum - nums[index] , index + 1);

        bool exclude = solve(nums, targetSum , index + 1);

        return include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int summedUp = accumulate(nums.begin(), nums.end(), 0);
        int targetSum = summedUp / 2;
        int index = 0;

        if(summedUp & 1)  return false;

        bool ans = solve(nums ,targetSum ,index);
        return ans ;

    }
};