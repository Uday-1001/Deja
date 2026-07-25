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
            int one_added_no = 0;
            int zero_added_no = 0;

            if(nums[i] == 1)
            {
                one_added_no = pow(2,ones);
                
                decimal[i] = decimal[i-1] + one_added_no;
            }
            else
            {
                if(ones > 0) zero_added_no = 2 * decimal[i-1];
                else zero_added_no = 0;

                decimal[i] = zero_added_no;
            }
        }
        
        for(auto ch : decimal) cout<<ch<<" ";
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans[i] = (decimal[i] == 0 or decimal[i] % 5 == 0) ? true : false;
        }

        return ans;
    }
};