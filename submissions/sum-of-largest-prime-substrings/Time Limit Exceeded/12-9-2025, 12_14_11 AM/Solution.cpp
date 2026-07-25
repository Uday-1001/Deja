// https://leetcode.com/problems/sum-of-largest-prime-substrings

class Solution {
public:
    vector<bool> primegen(int n)
    {
        vector<bool>isPrime(n+1 , true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2 ; i <= sqrt(n) ; i++)
        {
            if(isPrime[i])
            {
                for(int j = i*i ; j <= n ; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    long long sumOfLargestPrimes(string s) {
        int n = stoi(s);
        vector<bool>primes = primegen(n);
        set<int , greater<int>>st;

        for(int i=0 ; i<s.size() ; i++)
        {
            long long number = 0;
            for(int j = i ; j <s.size() ; j++)
            {
                number = number * 10 + (s[j] - '0');
                if(number > n) break;
                if(primes[number] == true) st.insert(number);
            }
        }

        long long sum = 0;
        if(st.size() < 3)
        {
            for(auto it : st) sum += it;
        }
        else
        {
            int size = 0;
            for(auto it : st)
            {
                if(size == 3) break;
                sum += it;
                size++;
            }
        }
    return sum;
    }
};