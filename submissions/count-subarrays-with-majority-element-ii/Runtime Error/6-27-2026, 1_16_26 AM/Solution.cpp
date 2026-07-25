// https://leetcode.com/problems/count-subarrays-with-majority-element-ii

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;

        int cumsum = 0;
        int count = 0;
        int leftsmallerones = 0;

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