// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    int mod = 1000000007;

    int bydp(int n, int k, int target , vector<vector<int>>&dp)
    {
        //base cases

        //jab mera target sum aagya ho aur dices bhio finish ho chuke ho 
        if(n == 0 && target == 0) return 1;

        //jab mera target nhi aaya ho but dices finish ho gye hai
        if(n == 0 || target <= 0) return 0;

        if(dp[target][n] != -1)
        {
            return dp[target][n];
        }

        //ek case hum solve karenge baaki recursion karlega 
        int way = 0;
        for(int i =1 ; i<=k ; i++)
        {
            way = (way + bydp(n-1 , k , target - i , dp)) % mod;
            dp[target][n] = way; 
        }
        return dp[target][n];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(target+1 , vector<int>(n+1 , -1));
        int ans = bydp(n , k , target , dp);
        return dp[target][n];
    }
};