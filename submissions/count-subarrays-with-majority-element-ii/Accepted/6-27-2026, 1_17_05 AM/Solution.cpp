// https://leetcode.com/problems/count-subarrays-with-majority-element-ii

class Solution {
public:
    using ll = long long;

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;

        ll cumsum = 0;
        ll count = 0;
        ll leftsmallerones = 0;

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] == target)
            {
                leftsmallerones += mp[cumsum];
                cumsum++;
            }
            else
            {
                cumsum--;
                leftsmallerones -= mp[cumsum];
            }
            mp[cumsum]++;
            count += leftsmallerones;
        }
        return count;
    }
};