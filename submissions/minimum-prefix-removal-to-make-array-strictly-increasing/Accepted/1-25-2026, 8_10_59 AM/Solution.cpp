// https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int non_increasing_elems = 0;
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]) continue;
            else
            {
                non_increasing_elems = i + 1;
                break;
            }
        }
    return non_increasing_elems;
    }
};