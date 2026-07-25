// https://leetcode.com/problems/binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int ones = 0;
        vector<bool>ans(nums.size() , false);
        vector<long long>decimal(nums.size() , 0);

        decimal[0] = (nums[0]) % 5;

        for(int i = 1 ; i<nums.size() ; i++)
        {
           decimal[i] = (decimal[i-1] * 2 + nums[i]) % 5;
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans[i] = (decimal[i] == 0);
        }

        return ans;
    }
};