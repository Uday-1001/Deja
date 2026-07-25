// https://leetcode.com/problems/partition-array-into-two-equal-product-subsets

class Solution {
public:
    int parts = 0;
    void byrec(vector<int>&nums , long long target , long long prod , int i)
    {
        if(i >= nums.size() or prod > target) return;
        if(prod == target)
        {
            parts++;
            return;
        }
        //include
        byrec(nums , target , prod * nums[i] , i+1);
        //exclude
        byrec(nums , target , prod , i+1);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int total = 1;
        for(auto num : nums) total *= num;

        if(total != target * target) return false;
        byrec(nums , target , 1LL , 0);
        return (parts >= 1);
    }
};