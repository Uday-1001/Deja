// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    // int dp[31];

    //By Memoization
    // int solve(int n)
    // {
    //     //base case 
    //     if(n <= 1)return n;
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = fib(n-1) + fib(n-2);
    // }

    //By Tabulation
    int solvebytab(int n)
    {
        //create a dp array
        vector<int>dp(n+1 , -1);
        //analyze base case 
        if(n == 0) return 0;
        dp[0] = 0;
        dp[1] = 1;

        //check parameter ,  reverse it and copy paste logic making it in dp using loop
        for(int i=2 ; i<=n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        //return ans 
        return dp[n];
    }

    int fib(int n) {
        // memset(dp , -1 , sizeof(dp));
        // return solve(n);
        return solvebytab(n);
    }
};