// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n+1 , 0);

        pref[0] = 0;
        pref[1] = nums[0];
        for(int i =2 ; i<=n ; i++) pref[i] = pref[i-1] + nums[i-1];

        unordered_map<int,int>mp;
        mp[0] = 1;

        int count = 0;
        for(int i = 1 ; i<n+1 ; i++)
        {
            int needed = pref[i] - k;
            if(mp.count(needed))
            {
                count ++;
            }
            mp[pref[i]]++;
        }
    return count;
    }
};