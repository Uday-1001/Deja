// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int solve(int n)
    {
        //base case
        if(n == 0) return 1;
        if(n < 0) return 0;
    
        //ek case hum solve karenge baaki recursion kardega
        int steps = 0;
        int ans = INT_MAX;

        for(int i=1 ; i<=sqrt(n) ; i++)
        {
            int square = i * i;
            steps = 1 + solve(n - square);
            ans = min(ans , steps);
        } 
    return ans;
    }

    int numSquares(int n) {
        return solve(n) - 1;
    }
};