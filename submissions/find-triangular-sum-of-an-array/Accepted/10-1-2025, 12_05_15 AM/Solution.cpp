// https://leetcode.com/problems/find-triangular-sum-of-an-array

class Solution {
public:
    int triangularSum(vector<int>& nums) {

        while(nums.size() != 1)
        {
            vector<int>temp(nums.size()-1);

            for(int i=0 ; i<nums.size(); i++)
            {
                if(i+1 < nums.size())
                {
                    temp[i] = (nums[i] + nums[i+1]) % 10;
                }
            }
            nums = temp;
        }
    return nums[0];
    }
};