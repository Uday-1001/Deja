// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    const int mod = 1e9 + 7;

    string to_binary(int n)
    {
        string ans = "";
        while(n > 0)
        {
            ans.push_back((n % 2) + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int contri(string &s , long long &tsum)
    {
        for(int i = 0; i < s.size(); i++)
        {
            tsum = (tsum * 2) % mod;      
            tsum = (tsum + (s[i] - '0')) % mod;
        }
        return tsum;
    }

    int concatenatedBinary(int n) {
        long long tsum = 0;

        for(int i = 1 ; i <= n ; i++)
        {
            string binary = to_binary(i);
            contri(binary , tsum);
        }

        return tsum % mod;
    }
};