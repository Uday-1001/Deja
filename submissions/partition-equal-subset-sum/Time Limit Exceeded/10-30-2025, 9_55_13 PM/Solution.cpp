// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool byrec(vector<int>&nums , int target , int i)
    {
        //base case 
        if(target == 0) return true;
        if(i >= nums.size() or target < 0) return false;

        int include = byrec(nums , target-nums[i] , i+1);
        int exclude = byrec(nums , target , i+1);

        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums) , end(nums) , 0);

        if(sum & 1) return false;
        int target = sum / 2;

        return byrec(nums , target , 0);
    }
};