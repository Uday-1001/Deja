// https://leetcode.com/problems/complete-prime-number

class Solution {
public:
    bool isPrime(long long n)
    {
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 or n % 3 == 0) return false;

        for(long long i=5 ; i*i<=n ; i+=6){
            if(n % i == 0 or n %(i+2) == 0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        long long prefix = 0;
        for(int i=0 ; i<n ; i++){
            prefix = prefix * 10 + (s[i] - '0');
            if(!isPrime(prefix)) return false;
        }

        long long suffix = 0 , place = 1;
        for(int i=n-1 ; i >= 0 ; i--){
            suffix = (s[i] - '0') * place + suffix;
            place *= 10;
            if(!isPrime(suffix)) return false;
        }

        return true;
    }
};