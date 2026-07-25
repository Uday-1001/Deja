// https://leetcode.com/problems/total-characters-in-string-after-transformations-i

class Solution {
public:
    int MOD  = 100000007;
   
    int solve(char ch , int t)
    {
        //base case 
        if(t == 0) return 1;

        if(ch == 'z')
        {
            return solve('a' , t-1) + solve('b' , t-1);
        }
        else
        {
            return solve(ch + 1 , t-1);
        }
    }

    int lengthAfterTransformations(string s, int t) {
        int total = 0;
        for(auto ch : s)
        {
            total = (total + solve(ch , t )) % MOD ;
        }
        return total;
        
    }
};