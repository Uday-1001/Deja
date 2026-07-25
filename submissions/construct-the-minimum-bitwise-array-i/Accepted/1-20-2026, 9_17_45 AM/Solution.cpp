// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , -1);
        
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<nums[i] ; j++)
            {
                int binary = j | (j+1);
                if(binary == nums[i])
                {
                    ans[i] = j;
                    break;
                } 
            }
        }
        return ans;
    }
};