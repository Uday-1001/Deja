// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    long long power(long long base, long long exp) 
    {
        long long ans = 1;
        while(exp > 0) 
        {
            if (exp % 2 == 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        ll evenidx = (n+1) / 2;
        ll oddidx = n - evenidx;

        ll evenans = (power(5 , evenidx)) % mod; 
        ll oddans = (power(4 , oddidx)) % mod;

        return (evenans * oddans) % mod;
    }
};