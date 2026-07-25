// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = INT_MAX;

        int total_val = accumulate(nums.begin() , nums.end() , 0);
        if(target > total_val) return 0;

        int sum = 0;
        for(int r = 0 ; r < n ; r++)
        {
            sum += nums[r];
            while(sum >= target)
            {
                ans = min(ans , r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return ans;
    }
};