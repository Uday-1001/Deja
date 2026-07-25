// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v

class Solution {
public: 
    using ll = long long;
    long long byrec(vector<int>&prices , int k , int i , int type , vector<vector<vector<ll>>>&dp)
    {
        //base case
        if(i >= prices.size())
        {
            if(type == 0) return 0;
            return INT_MIN;
        }
        if(dp[i][k][type] != -1) return dp[i][k][type];

        //first we split our ways into 3 parts -> buy , shortsell or skip the transaction

        //dont take the stock
        ll exclude = 0 + byrec(prices , k , i+1 , type , dp);

        //buying the stock and then selling
        ll include = 0;
        if(k > 0)
        {
            if(type == 1)
            {
                include = prices[i] + byrec(prices , k-1 , i+1 , 0 , dp);
            }
            //shortselling and then rebuying
            else if(type == 2)
            {
                include = -prices[i] + byrec(prices , k-1 , i+1 , 0 , dp);
            }
            //neutral transaction
            else 
            {
                ll buy = -prices[i] + byrec(prices , k , i+1 , 1 , dp);
                ll shortsell = prices[i] + byrec(prices , k , i+1 , 2 , dp);
                include = max(buy , shortsell);
            }
        }

        return dp[i][k][type] = max(include , exclude);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>>dp(n+1 , vector<vector<ll>>(k+1 , vector<ll>(3 , -1)));
        return byrec(prices , k , 0 , 0 , dp);
    }
};