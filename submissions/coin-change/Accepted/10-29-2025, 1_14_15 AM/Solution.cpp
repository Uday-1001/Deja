// https://leetcode.com/problems/coin-change

class Solution {
public:
    // int bymemo(vector<int>&coins , int amount , vector<int>&dp)
    // {
    //     if(amount == 0) return 0; 
    //     if(dp[amount] != -1) return dp[amount];
        
    //     //we will solve one case only 
    //     int mini = INT_MAX;

    //     for(int i=0 ; i<coins.size() ; i++)
    //     {
    //         int coin_val = coins[i];
    //         if(coin_val <= amount)
    //         {
    //             int aage_ka_ans = bymemo(coins , amount - coin_val , dp);

    //             if(aage_ka_ans != INT_MAX)
    //             {
    //                 int coins_used = 1 + aage_ka_ans;
    //                 mini = min(mini , coins_used);
    //             }
    //         }
    //     }
    //     return dp[amount] = mini;
    // }

    int bytab(vector<int>&coins , int amount)
    {
        vector<int>dp(amount+1 , -1);

        //analyse the base case and update the dp array
        dp[0] = 0;

        for(int amt=1 ; amt<=amount ; amt++)
        {
            int mini = INT_MAX;
            for(int i=0 ; i<coins.size() ; i++)
            {
                int coin_val = coins[i];
                if(coin_val <= amt)
                {
                    int aage_ka_ans = dp[amt - coin_val];

                    if(aage_ka_ans != INT_MAX)
                    {
                        int coins_used = 1 + aage_ka_ans;
                        mini = min(mini , coins_used);
                    }
                }
            }
            dp[amt] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1 , -1);
        // int ans = bymemo(coins  , amount , dp);
        int ans = bytab(coins , amount);

        return (ans == INT_MAX) ? -1 : ans;
    }
};