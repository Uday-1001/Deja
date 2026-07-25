// https://leetcode.com/problems/number-of-substrings-with-only-1s

class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {
        long long cont_one = 0;
        long long ans = 0;
        for(auto ch : s)
        {
            if(ch == '1') cont_one++;
            else
            {
                ans += (cont_one*(cont_one+1))/2;
                cont_one = 0;
            }
        }
    ans += (cont_one*(cont_one+1))/2;
    return ans % mod;
    }
};