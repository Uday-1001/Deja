// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mapping;
        mp[0]++;
        vector<int>presum(nums.size());
        vector<int>remainder;

        if(nums.size() == 1) return false;

        int sum = 0;
        for(int i= 0 ; i<nums.size() ;i++)
        {   
            sum += nums[i];
            presum[i] = sum;
        }
        for(int i= 0 ; i<presum.size() ;i++)
        {
            remainder.push_back(presum[i] % k);
        }
        for(int i = 1; i<remainder.size() ;i++)
        {
            if(mapping.find(remainder[i]) != mapping.end())
            {
                return true;
            }
            mapping[remainder[i-1]]++;
        }
        return false;
    }
};