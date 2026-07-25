// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;

    string to_binary(int n)
    {
        string ans = "";
        while(n > 0)
        {
            ans.push_back((n % 2) + '0');
            n /= 2;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    
    int contri(string &s , ll &power)
    {
        ll sum = 0;

        for(int i = s.size()-1 ; i>=0 ; i--)
        {
            int digit = s[i]- '0';

            if(digit == 1)
            {
                long long val = 1;
                for(int j = 0 ; j < power ; j++) val = (val * 2) % mod;
                sum = (sum + val) % mod;
            }
            power++;   
        }
        return sum % mod;
    }

    int concatenatedBinary(int n) {
        ll tsum = 0;
        ll power = 0;
        for(int i = n ; i>= 1 ; i--)
        {
            string binary = to_binary(i);
            int total_contribution = contri(binary , power);
            tsum += total_contribution;
        }
    return tsum % mod;
    }
};