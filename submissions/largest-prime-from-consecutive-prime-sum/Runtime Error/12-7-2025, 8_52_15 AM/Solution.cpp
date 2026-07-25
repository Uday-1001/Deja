// https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum

class Solution {
public:
    vector<bool> primegen(int n)
    {
        vector<bool>primes(n+1 , true);
        primes[0] = primes[1] = false;

        for(int i = 2 ; i * i <= n ; i++){
            if(primes[i])
            {
                for(int j = i*i ; j <= n ; j +=i){
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    
    int largestPrime(int n) {
        vector<bool>isPrime = primegen(n);

        vector<int>primes;
        for(int i=2 ; i<=n ; i++){
            if(isPrime[i]) primes.push_back(i);
        }
        
        vector<int>primesum(primes.size() , 0);
        primesum[0] = primes[0];

        for(int i = 1 ; i <primes.size() ; i++){
            primesum[i] = primesum[i-1] + primes[i];
        }
        
        int maxi = 0;
        for(int i = 0 ; i < primesum.size() ; i++){
            long long s = primesum[i];
            if(s > n) break;
            if(isPrime[s]) maxi = s;
        }
    return maxi;
    }
};