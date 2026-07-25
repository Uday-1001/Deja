// https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(rbegin(nums) , rend(nums));

        long long ans = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(k == 0) break;
            if(mul > 0) ans += (mul * nums[i] * 1LL);
            else ans += nums[i];
            mul--;
            k--;
        }
        return ans;
    }
};