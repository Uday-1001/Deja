// https://leetcode.com/problems/maximum-valid-pair-sum

class Solution {
public:
    using ll = long long;
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n), suff(n);

        pref[0] = nums[0];
        for(int i = 1 ; i < n ; i++) pref[i] = max(pref[i-1], nums[i]);

        suff[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--) suff[i] = max(suff[i+1], nums[i]);

        int ans = INT_MIN;

        for(int i = 0 ; i < n ; i++)
        {
            if(i-k >= 0)
            {
                ans = max(ans, nums[i] + pref[i-k]);
            }

            if(i+k < n)
            {
                ans = max(ans, nums[i] + suff[i+k]);
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};