// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations

class Solution {
public:
    long long factorial(long long n)
    {
        long long fact = 1;
        for(int i=1 ; i<=n ; i++) fact*=i;
        return fact;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        sort(complexity.begin() , complexity.end());
        
        bool canunlock = true;
        for(int i=1 ; i+1<complexity.size() ; i++)
        {
            if(complexity[0] >= complexity[i+1]) canunlock = false;
        }
        return (canunlock == true) ? factorial(n-1) : 0;
    }
};