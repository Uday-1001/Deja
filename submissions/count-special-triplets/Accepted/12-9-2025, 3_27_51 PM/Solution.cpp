// https://leetcode.com/problems/count-special-triplets

class Solution {
public:
    const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int>allelements(1e5+1 , 0);
        vector<int>leftones(1e5+1 , 0);

        for(auto n : nums) allelements[n]++;

        long long count = 0;
        for(int i=0 ; i<n ; i++)
        {
            int val = nums[i];
            int target = val * 2;

            allelements[val]--;

            if(target <= 1e5)
            {
                long long left_occ = leftones[target];
                long long right_occ = allelements[target];
                count = (count + (left_occ * right_occ) % mod) % mod;
            }
            
            leftones[val]++;
        }
    return count;
    }
};