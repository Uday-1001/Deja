// https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(rbegin(nums) , rend(nums));

        long long ans = 0;
        int count = min(k , max(0 , mul - 1));
        
        for(int i = 0 ; i<count ; i++) ans += 1LL * nums[i] * (mul-i);

        for(int i = count ; i<k ; i++) ans += nums[i];
        return ans;
    }
};