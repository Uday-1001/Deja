// https://leetcode.com/problems/intervals-between-identical-elements

class Solution {
public:
    using ll = long long;
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<ll>> mp;

        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<long long> ans(arr.size(), 0);

        for(auto &it : mp)
        {
            vector<ll> &v = it.second;
            int n = v.size();

            if(n == 1) continue;

            vector<ll> prefix(n, 0);
            prefix[0] = v[0];

            for(int i = 1; i < n; i++)
            {
                prefix[i] = prefix[i - 1] + v[i];
            }

            ll total = prefix[n - 1];

            for(int i = 0; i < n; i++)
            {
                ll leftSum = 0;
                if(i > 0) leftSum = prefix[i - 1];

                ll rightSum = total - prefix[i];

                ll left = (v[i] * i) - leftSum;
                ll right = rightSum - (v[i] * (n - i - 1));

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};