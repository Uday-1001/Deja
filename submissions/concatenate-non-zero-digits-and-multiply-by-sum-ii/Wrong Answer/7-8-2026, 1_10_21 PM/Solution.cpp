// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii

class Solution {
public:
    using ll = long long;
    int mod = 1e9+7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int>ans;
        
        vector<int>pos;
        vector<ll>prefsum;
        vector<ll>valuestillnow;
        vector<ll>powerof10(n);

        powerof10[0] = 1;
        for(int i = 1 ; i<n ; i++) powerof10[i] = (powerof10[i-1] * 10LL) % mod;

        for(int i = 0 ; i<n; i++)
        {
            if(s[i] != '0')
            {
                pos.push_back(i);
                prefsum.push_back(((prefsum.empty() ? 0 : prefsum.back()) + (s[i] - '0')) % mod);
                ll prev = valuestillnow.empty() ? 0 : valuestillnow.back();
                valuestillnow.push_back((prev * 10 + (s[i] - '0')) % mod);
            }
        }    

        for(auto query : queries)
        {
            int left = query[0];
            int right = query[1];

            int leftindex = lower_bound(begin(pos) , end(pos) , left) - pos.begin();
            int rightindex = upper_bound(begin(pos) , end(pos) , right) - pos.begin() - 1;

            if(leftindex > rightindex) 
            {
                ans.push_back(0);
                continue;
            }
            
            ll sum = prefsum[rightindex];
            if(leftindex > 0) sum = (sum - prefsum[leftindex - 1]) % mod;

            ll value = valuestillnow[rightindex];
            if(leftindex > 0)
            {
                value = (value - (valuestillnow[leftindex - 1] * powerof10[rightindex - leftindex + 1]) % mod) % mod;
            }

            ans.push_back((sum * value) % mod);
        } 
        return ans;
    }
};