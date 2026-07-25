// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int solve(vector<int>&prices)
    {
        int mini = INT_MAX;
        int ans = 0;

        for(int i = 0 ; i<prices.size() ; i++)
        {
            mini = min(mini , prices[i]);
            ans = max(ans , (prices[i] - mini));
        }
        return ans;
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};