// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int byrec(vector<int>& nums, int curr, int prev){
        //base case
        if(curr >= nums.size()) return 0;
        
        //ek case hum solve karenge
        int include = 0; 
        if(prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + byrec(nums, curr+1 , curr);
        }
        int exclude = 0 + byrec(nums, curr+1 , prev);

        return max(include , exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        return byrec(nums, 0, -1);
    }
};