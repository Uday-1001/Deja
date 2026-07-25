// https://leetcode.com/problems/minimum-removals-to-balance-array

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int l = 0;
        int maxlen = 1;

        for(int r = 0; r < n ; r++)
        {
            int maxelem = nums[r];
            if(maxelem > k * nums[l]) l++;

            if(maxelem <= k * nums[l]) maxlen = max(maxlen , r-l+1); 
        }
        return n - maxlen;
    }
};