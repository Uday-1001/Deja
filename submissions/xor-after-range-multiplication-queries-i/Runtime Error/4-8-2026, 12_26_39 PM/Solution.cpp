// https://leetcode.com/problems/xor-after-range-multiplication-queries-i

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it : queries)
        {
            int left = it[0];
            int right = it[1];
            int k = it[2];
            int val = it[3];

            for(int i = left ; i<=right ; i+=k) nums[i] *= val;
        }

        int ans = 0;
        for(auto it : nums) ans ^= it;
        return ans;
    }
};