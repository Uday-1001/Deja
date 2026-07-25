// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int n , int k , int target)
    {
        //base case
        if(n == 0 and target == 0) return 1;
        if(n == 0 or target <= 0) return 0;

        //ek case hum solve karenge 
        int ways = 0;
        for(int i = 1 ; i<=k ; i++)
        {
            ways = (ways + solve(n - 1 , k , target - i)) % mod;
        }
        return ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        int ans = (solve(n , k , target)) % mod;
        return ans;
    }
};