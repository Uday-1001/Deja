// https://leetcode.com/problems/sum-of-largest-prime-substrings

class Solution {
public:
    vector<bool> primegen(int n)
    {
        vector<bool>isPrime(n+1 , true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2 ; i*i <= n ; i++)
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
        for(auto it:primes) cout<<it<<" ";
        set<int>st;

        for(int i=0 ; i<s.size() ; i++)
        {
            for(int j = i ; j <s.size() ; j++)
            {
                int str = s[j] - '0';
                if(primes[str] == true) st.insert(str);
            }
        }
        int sum = 0;
        if(st.size() < 3)
        {
            for(auto it : st) sum += it;
        }
        else
        {
            int size = 0;
            for(auto it : st)
            {
                sum += it;
                if(size == 3) break;
                size++;
            }
        }
    return sum;
    }
};