// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int mini = INT_MAX;
        vector<int>pref(n , 0);
        vector<int>suff(n , 0);

        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1 ; i<n ; i++)
        {
            pref[i] = pref[i-1] + nums[i];
        }
        for(int i = n-2 ; i>=0 ; i--)
        {
            suff[i] = suff[i+1] + nums[i];
        }

        if(pref[n-1] % p == 0) return 0;
        
        for(int i = 0; i<n ; i++)
        {
            if(pref[i] % p == 0 or suff[i] % p == 0) return abs(n - i - 1);
        }

        return 0;

    }
};