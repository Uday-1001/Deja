// https://leetcode.com/problems/coin-change

class Solution {
public:
    int dp[10001];
    int solve(vector<int>&coins , int amount)
    {
        if(amount == 0) return 0; 
        if(dp[amount] != -1) return dp[amount];
        
        //we will solve one case only 
        int mini = INT_MAX;

        for(int i=0 ; i<coins.size() ; i++)
        {
            int coin_val = coins[i];
            if(coin_val <= amount)
            {
                int aage_ka_ans = solve(coins , amount - coin_val);

                if(aage_ka_ans != INT_MAX)
                {
                    int coins_used = 1 + aage_ka_ans;
                    mini = min(mini , coins_used);
                }
            }
        }
        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp , -1 , sizeof(dp));
        int ans = solve(coins  , amount);
        if(ans == INT_MAX) 
            return -1;
        else
        return ans;
    }
};