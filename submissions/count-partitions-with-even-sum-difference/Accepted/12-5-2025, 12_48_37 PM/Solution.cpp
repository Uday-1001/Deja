// https://leetcode.com/problems/count-partitions-with-even-sum-difference

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n , 0);
        vector<int>suff(n , 0);
        int parts = 0;

        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i=1 ; i<n ; i++)
        {
            pref[i] = pref[i-1] + nums[i];
        }
        for(int i = n-2 ; i>=0 ; i--)
        {
            suff[i] = suff[i+1] + nums[i];
        }

        for(int i=1 ; i<n ; i++)
        {
            if(abs((pref[i-1] - suff[i]) % 2 == 0)) parts++;
        }
        return parts;
    }
};