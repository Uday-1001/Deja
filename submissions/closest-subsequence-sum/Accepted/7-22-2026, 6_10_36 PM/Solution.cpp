// https://leetcode.com/problems/closest-subsequence-sum

class Solution {
public:
    using ll = long long;

    void solve(int idx, int end, ll sum, vector<ll>&v, vector<int>&nums)
    {
        if(idx == end)
        {
            v.push_back(sum);
            return;
        }

        solve(idx + 1, end, sum, v, nums);
        solve(idx + 1, end, sum + nums[idx], v, nums);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<ll> left, right;

        solve(0, n / 2, 0, left, nums);
        solve(n / 2, n, 0, right, nums);

        sort(right.begin(), right.end());

        ll ans = LLONG_MAX;

        for(auto x : left)
        {
            ll need = goal - x;

            auto lb = lower_bound(right.begin(), right.end(), need);
            auto ub = upper_bound(right.begin(), right.end(), need);

            if(lb != right.end()) ans = min(ans, llabs(goal - (x + *lb)));
            if(ub != right.end()) ans = min(ans, llabs(goal - (x + *ub)));
            if(ub != right.begin())
            {
                ub--;
                ans = min(ans, llabs(goal - (x + *ub)));
            }
        }

        return ans;
    }
};