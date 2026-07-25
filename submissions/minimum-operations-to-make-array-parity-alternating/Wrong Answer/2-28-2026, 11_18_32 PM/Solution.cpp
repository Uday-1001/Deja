// https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2);

        int mismatched = 0;
        int maxval = *max_element(nums.begin() , nums.end());
        int minval = *min_element(nums.begin() , nums.end());
        int oprs = 0;

        for(int i = 1 ; i<n ; i++)
        {
            if((abs(nums[i]) % 2 == 1 and abs(nums[i-1]) % 2 == 0) or (abs(nums[i]) % 2 == 0 and abs(nums[i-1]) % 2 == 1)) continue;
            else mismatched++;

            if(mismatched > 0)
            {
                if(abs(nums[i] - maxval) < abs(nums[i] - minval))
                {
                    nums[i]--;
                }
                else nums[i]++;

                mismatched = 0;
                oprs++;
            }
        }

        int new_maxval = *max_element(nums.begin() , nums.end());
        int new_minval = *min_element(nums.begin() , nums.end());
        ans[0] = oprs;
        ans[1] = new_maxval - new_minval;
        return ans;
    }
};