// https://leetcode.com/problems/sum-of-largest-prime-substrings

class Solution {
public:
    vector<bool> primegen(int n)
    {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i*i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

    long long sumOfLargestPrimes(string s) {
        int n = stoi(s);
        vector<bool> primes = primegen(n);

        long long top1 = -1, top2 = -1, top3 = -1;

        int len = s.size();

        for(int i = 0; i < len; i++)
        {
            long long num = 0;

            for (int j = i; j < len; j++)
            {
                num = num * 10 + (s[j] - '0');

                if(primes[num]) 
                {
                    if(num > top1) 
                    {
                        top3 = top2;
                        top2 = top1;
                        top1 = num;
                    }
                    else if(num > top2) 
                    {
                        top3 = top2;
                        top2 = num;
                    }
                    else if(num > top3) 
                    {
                        top3 = num;
                    }
                }
            }
        }

        long long sum = 0;
        set<int , greater<int>>st;
        st.insert(top1);
        st.insert(top2);
        st.insert(top3);

        if(st.size() < 3)
        {
            for(auto it: st) 
            {
                if(it != -1) sum += it;
            }
        } 
        else 
        {
            sum = top1 + top2 + top3;
        }

        return sum;
    }
};
