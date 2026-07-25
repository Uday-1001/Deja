// https://leetcode.com/problems/coin-change

class Solution {
public:
    int solve(vector<int>& coins, int amount){
        if(amount == 0)
        {
            return 0;
        }
        int coins_req = INT_MAX;
        for(int i = 0 ;i<coins.size() ;i ++)
        {
            int value = coins[i];

            if(value <= amount)
            {
                int recursion_ans = solve(coins,amount - value);
            
            if(recursion_ans != INT_MAX){

                int coin_used = 1 + recursion_ans;
                coins_req = min(coins_req , coin_used);
            }
        }
    }
    return coins_req;  
}
    int coinChange(vector<int>& coins, int amount) {
        int ans =solve(coins,amount);
        if (ans == INT_MAX)
        return -1;
        return ans;
    }
};