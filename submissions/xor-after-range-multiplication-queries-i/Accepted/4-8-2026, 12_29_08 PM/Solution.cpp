// https://leetcode.com/problems/xor-after-range-multiplication-queries-i

class Solution {
public:
    const int mod = 1e9+7;
    using ll = long long;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it : queries)
        {
            ll left = it[0];
            ll right = it[1];
            ll k = it[2];
            ll val = it[3];

            for(int i = left ; i<=right ; i+=k) nums[i] = ((ll)nums[i] * (ll)val) % mod;
        }

        ll ans = 0;
        for(auto it : nums) ans ^= it;
        return ans;
    }
};