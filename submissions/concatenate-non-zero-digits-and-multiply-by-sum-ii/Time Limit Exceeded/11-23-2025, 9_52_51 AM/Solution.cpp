// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii

class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ansvec;
        for (auto &range : queries) {
            int start = range[0];
            int end = range[1];
            long long sum = 0;
            long long ans = 0;
            for (int i = start; i <= end; i++) 
            {
                if (s[i] != '0') 
                {
                    int digit = s[i] - '0';
                    ans = (ans * 10) % mod;
                    ans += digit;

                    sum += digit;
                }
            }
            long long n_ans = (ans * sum) % mod;
            ansvec.push_back((int)n_ans);
        }
        return ansvec;
    }
};