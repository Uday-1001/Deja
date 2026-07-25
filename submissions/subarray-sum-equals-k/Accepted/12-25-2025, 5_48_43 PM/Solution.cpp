// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>presum(n + 1 , 0);
        unordered_map<int,int>mp;
        mp[0] = 1;

        presum[0] = 0;
        presum[1] = nums[0];
        for(int i = 2 ; i<=n ; i++)
        {
            presum[i] = presum[i-1] + nums[i-1];
        }

        int count = 0;
        for(int i = 1 ; i<presum.size() ; i++)
        {
            int val_to_find = presum[i] - k;
            if(mp.count(val_to_find))
            {
                count += mp[val_to_find];
            }
            mp[presum[i]]++;
        }
    return count;
    }
};