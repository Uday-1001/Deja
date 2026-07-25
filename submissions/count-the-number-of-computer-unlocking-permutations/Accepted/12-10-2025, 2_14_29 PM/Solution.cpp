// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations

class Solution {
public:
    const int mod = 1e9 + 7;
    long long factorial(long long n)
    {
        long long fact = 1;
        for(int i=1 ; i<=n ; i++) fact = (fact * i) % mod;
        return fact;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        int mini = INT_MAX;        
        for(int i=1 ; i<complexity.size() ; i++)
        {
            //agar aage koi computer hai jo unlock kr sakta h sbko to usse he unlock krva lo
            mini = min(mini , complexity[i]);
        }

        return (mini > complexity[0]) ? factorial(n-1) : 0;
    }
};