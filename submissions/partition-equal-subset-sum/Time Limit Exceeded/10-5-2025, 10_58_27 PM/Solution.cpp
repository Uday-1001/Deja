// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool solve(vector<int>&nums , int target , int index)
    {
        //base case 
        if(index >= nums.size()) return false;
        if(target == 0) return true;

        //we will solve one case only 
        bool include = solve(nums , target - nums[index] , index+1);
        bool exclude = solve(nums , target , index+1);

        return include||exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums) , end(nums) , 0);
        int target = sum / 2;

        if(sum & 1) return false;

        return solve(nums , target , 0);
    }
};