// https://leetcode.com/problems/coin-change

class Solution {
public:
    int solve(vector<int>&coins , int amount)
    {
        if(amount <= 0) return 0; 
        if(coins.size() == 1 && coins[0] < amount) return -1;
        
        //we will solve one case only 
        int mini = INT_MAX;

        for(int i=0 ; i<coins.size() ; i++)
        {
            int coin_val = coins[i];
            int aage_ka_ans = solve(coins , amount - coin_val);

            if(aage_ka_ans != INT_MAX)
            {
                int coins_used = 1 + aage_ka_ans;
                mini = min(mini , coins_used);
            }
        }
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        return solve(coins  , amount);
    }
};