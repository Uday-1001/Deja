// https://leetcode.com/problems/number-of-substrings-with-only-1s

class Solution {
public:
    const int mod = 1e9+7;
    int numSub(string s) {
        int cont_one = 0;
        int ans = 0;
        for(auto ch : s)
        {
            if(ch == '1') cont_one++;
            else
            {
                ans += ((cont_one*(cont_one+1) % mod)/2) % mod;
                cont_one = 0;
            }
        }
    ans += ((cont_one*(cont_one+1) % mod)/2) % mod;
    return ans % mod;
    }
};