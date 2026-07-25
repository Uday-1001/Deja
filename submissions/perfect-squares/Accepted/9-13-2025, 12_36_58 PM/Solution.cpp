// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int dp[10001];

    int bymem(int n)
    {
        //base case
        if(n == 0) return 1;
        // if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];
    
        //ek case hum solve karenge baaki recursion kardega
        int steps = 0;
        int ans = INT_MAX;

        for(int i=1 ; i<=sqrt(n) ; i++)
        {
            int square = i * i;
            steps = 1 + bymem(n - square);
            ans = min(ans , steps);
        } 
        return dp[n] = ans;
    }

    int numSquares(int n) {
        
        memset(dp , -1 , sizeof(dp));
        return bymem(n) - 1;
    }
};