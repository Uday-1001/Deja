// https://leetcode.com/problems/coin-change

class Solution {
public:
    int solve(vector<int>& coins, int amount)
    {
        //base case 
        if(amount == 0) return 0;

        // ek case hum solve karenge baaki recursion sambhalega
        int min_coin_req = INT_MAX;
        for(auto coin : coins)
        {
            if(coin <= amount)
            {
                int recursive_ans = solve(coins , amount - coin);
                
                if(recursive_ans != INT_MAX)
                {
                    int coins_used = 1 + recursive_ans;
                    min_coin_req = min(coins_used , min_coin_req);
                }
            }  
        }
        return min_coin_req;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins , amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};