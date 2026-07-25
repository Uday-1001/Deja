// https://leetcode.com/problems/count-special-triplets

class Solution {
public:
    const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffix(1e5+1 , 0);
        vector<int>prefix(1e5+1 , 0);

        for(auto n : nums) suffix[n]++;

        long long count = 0;
        for(int i=0 ; i<n ; i++)
        {
            int val = nums[i];
            int target = val * 2;

            suffix[val]--;

            if(target <= 1e5)
            {
                long long left_occ = prefix[target];
                long long right_occ = suffix[target];
                count = (count + (left_occ * right_occ) % mod) % mod;
            }
            
            prefix[val]++;
        }
    return count;
    }
};