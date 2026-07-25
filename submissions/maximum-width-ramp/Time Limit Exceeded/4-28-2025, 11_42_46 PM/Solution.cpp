// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        for(int i= 0 ; i<nums.size() ; i++)
            {
                for(int j = nums.size()-1 ; j>i ; j--)
                {
                    if(nums[i] <= nums[j])
                    {
                        ans = max(ans , j-i);
                        break;
                    }
                }
            }
        return ans;
    }
};