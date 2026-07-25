// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>copy = nums;
        sort(nums.begin() , nums.end());

        int min_len = INT_MAX;
        int l = 0 , r = nums.size()-1;
        while(l < r)
        {
            if(copy[l] == nums[l] and copy[r] == nums[r])
            {
                l++; 
                r--;
            }
            else if(copy[l] != nums[l] and copy[r] == nums[r]) r--;
            else if(copy[l] == nums[l] and copy[r] != nums[r]) l++;
            else 
            {
                min_len = min(min_len , r - l + 1);
                break;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};