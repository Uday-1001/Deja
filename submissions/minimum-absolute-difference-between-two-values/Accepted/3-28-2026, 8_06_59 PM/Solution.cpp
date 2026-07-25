// https://leetcode.com/problems/minimum-absolute-difference-between-two-values

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int diff = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = 0 ; j<nums.size() ; j++){
                if(nums[i] == 1 and nums[j] == 2) 
                {
                    diff = min(diff , abs(i - j));
                }
            }
        }
    return diff == INT_MAX ? -1 : diff;
    }
};