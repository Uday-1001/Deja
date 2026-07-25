// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    const int mod = 1e9 + 7;
    
    int byspace_op(int copy_n , int k , int copy_target)
    {
        vector<int>curr(copy_target + 1 , 0);
        vector<int>prev(copy_target + 1 , 0);

        prev[0] = 1;

        for(int n = 1 ; n <= copy_n ; n++)
        {
            for(int target = 1 ; target <= copy_target ; target++)
            {
                int ways = 0;
                for(int i = 1 ; i<=k ; i++)
                {
                    if(target - i >= 0)
                    ways = (ways + prev[target - i]) % mod;
                }
                curr[target] = ways;
            }
        prev = curr;
        }
    return curr[copy_target]; 
    }

    // int bytab(int copy_n , int k , int copy_target)
    // {
    //     vector<vector<int>>dp(copy_n+1 , vector<int>(copy_target+1 , 0));

    //     dp[0][0] = 1;

    //     for(int n = 1 ; n <= copy_n ; n++)
    //     {
    //         for(int target = 1 ; target <= copy_target ; target++)
    //         {
    //             int ways = 0;
    //             for(int i = 1 ; i<=k ; i++)
    //             {
    //                 if(target - i >= 0)
    //                 ways = (ways + dp[n-1][target - i]) % mod;
    //             }
    //             dp[n][target] = ways;
    //         }
    //     }
    // return dp[copy_n][copy_target];    
    // }
    
    // int bymemo(int n , int k , int target , vector<vector<int>>&dp)
    // {
    //     if(n == 0 and target == 0) return 1;
    //     if(n == 0 or target <= 0) return 0;
    //     if(dp[n][target] != -1) return dp[n][target];

    //     int ways = 0;
    //     for(int i = 1 ; i<=k ; i++)
    //     {
    //         ways = (ways + bymemo(n - 1 , k , target - i , dp)) % mod;
    //     }
    //     return dp[n][target] = ways;
    // }

    // int solve(int n , int k , int target)
    // {
    //     //base case
    //     if(n == 0 and target == 0) return 1;
    //     if(n == 0 or target <= 0) return 0;

    //     //ek case hum solve karenge 
    //     int ways = 0;
    //     for(int i = 1 ; i<=k ; i++)
    //     {
    //         ways = (ways + solve(n - 1 , k , target - i)) % mod;
    //     }
    //     return ways;
    // }

    int numRollsToTarget(int n, int k, int target) {
        // int ans = (solve(n , k , target)) % mod;
        // return ans;

        // vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1));
        // return bymemo(n , k , target , dp);

        // return bytab(n , k , target);

        return byspace_op(n , k , target);
    }
};