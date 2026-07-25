// https://leetcode.com/problems/minimum-cost-to-partition-a-binary-string

class Solution {
public:
    using ll = long long;
    vector<ll>pref;

    ll minfxn(string &s , int &ec , int &fc , int start , int end)
    {
        ll size = end - start + 1;
        ll bulkcost = 0;
        ll splitcost = 0;

        int ones = pref[end + 1] - pref[start];
        bulkcost += (ones == 0) ? fc : (1LL * size * ones * ec);

        if(size % 2 == 1) return bulkcost;

        ll mid = (start + end) / 2;

        splitcost += (minfxn(s , ec , fc , start , mid) + minfxn(s , ec , fc , mid + 1 , end));

        return min(bulkcost , splitcost);
    }

    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();

        pref.resize(n+1);

        for(int i = 0 ; i<n ; i++)
        {
            pref[i+1] = pref[i] + (s[i] == '1');
        }
        // for(auto it : pref) cout<<it<<" ";

        return minfxn(s , encCost , flatCost , 0 , n-1);
    }
};