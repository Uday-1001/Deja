// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool recursion(vector<int>& nums , int i , int target_sum)
    {
        //base case
        if(target_sum == 0) return true;
        if(i >=nums.size() or target_sum < 0) return false;

        //ek case hum solve krenge baaki recursion dekhlega
        //include 
        int include = recursion(nums , i+1 , target_sum - nums[i]);

        //exclude
        int exclude = recursion(nums , i+1 , target_sum);

        return include or exclude;

    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(sum & 1) return false;
        
        int target_sum = sum / 2;
        return recursion(nums,0,target_sum);
    }
};