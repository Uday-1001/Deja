// https://leetcode.com/problems/sum-of-largest-prime-substrings

class Solution {
public:
    using ll = long long;
    bool isPrime(ll n) 
    {
        if (n < 2) return false; 

        for (ll i = 2; i*i <= n; i++)
        {
           if (n % i == 0) return false;
        }    
        return true;
    }

    ll sumOfLargestPrimes(const string &s) {
        vector<ll>primes;
        for(ll i = 0; i < s.size(); i++) 
        {
            ll temp = 0;
            for(ll j = i; j < s.size(); j++) 
            {
                temp = temp * 10 + (s[j] - '0');
                if (isPrime(temp)) 
                {
                    primes.emplace_back(temp);
                }
            }
        }

        sort(primes.begin(), primes.end());
        primes.erase(unique(primes.begin(), primes.end()), primes.end());
        ll m = primes.size();
        if (m < 3) return accumulate(primes.begin(), primes.end(),0ll);
        return primes[m - 1] + primes[m - 2] + primes[m - 3];
    }
};