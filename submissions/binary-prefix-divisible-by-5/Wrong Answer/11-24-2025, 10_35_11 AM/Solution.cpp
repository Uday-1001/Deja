// https://leetcode.com/problems/binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int ones = 0;
        vector<bool>ans(nums.size() , false);
        vector<int>decimal(nums.size() , 0);
        if(nums[0] == 0) decimal[0] = 0;
        else
        {
            decimal[0] = 1;
            ones++;
        } 

        for(int i = 1 ; i<nums.size() ; i++)
        {
            decimal[i] = decimal[i-1] + (nums[i] == 1 ? pow(2 , ones) : 0);
            if(nums[i] == 1) ones++;
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans[i] = (nums[i] == 0 or nums[i] % 5 == 0) ? true : false;
        }
        
        return ans;
    }
};