// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int oprs = 0;

        if(is_sorted(nums.begin() , nums.end())) return 0;

        while(!is_sorted(nums.begin() , nums.end()))
        {
            int n = nums.size();
            int min_sum = INT_MAX;
            int lowest_idx = -1;

            for(int i = 0 ; i+1<n ; i++)
            {
                int pair_sum = nums[i] + nums[i+1];
                if(pair_sum < min_sum)
                {
                    min_sum = pair_sum;
                    lowest_idx = i;
                }
            }
            nums[lowest_idx] = min_sum;
            nums.erase(nums.begin() + (lowest_idx+1));
            oprs++;

            if(is_sorted(nums.begin() , nums.end())) break;
        }
        return oprs;
    }
};