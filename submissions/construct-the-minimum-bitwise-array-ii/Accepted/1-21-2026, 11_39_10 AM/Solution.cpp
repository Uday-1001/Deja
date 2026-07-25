// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , -1);

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] == 2) ans[i] = -1;
            
            for(int j = 0 ; j<32 ; j++)
            {
                //if it is set bit then skip
                if(nums[i] & (1<<j)) continue;
                else
                {
                    if(j == 0) break;
                    //make previous bit zero to get x
                    int prev_bit_pos = j-1;
                    //taking the XOR of shhifted one by j-1 times gives the desired x
                    ans[i] = nums[i] ^ (1 << prev_bit_pos);
                    break;
                }
            }
        }
    return ans;
    }
};