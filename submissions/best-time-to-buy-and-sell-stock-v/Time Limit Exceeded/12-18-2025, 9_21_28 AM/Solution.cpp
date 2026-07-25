// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v

class Solution {
public: 
    using ll = long long;
    long long byrec(vector<int>&prices , int k , int i , int type)
    {
        //base case
        if(i >= prices.size())
        {
            if(type == 0) return 0;
            return INT_MIN;
        }

        //first we split our ways into 3 parts -> buy , shortsell or skip the transaction

        //dont take the stock
        ll exclude = 0 + byrec(prices , k , i+1 , type);

        //buying the stock and then selling
        ll include = 0;
        if(k > 0)
        {
            if(type == 1)
            {
                include = prices[i] + byrec(prices , k-1 , i+1 , 0);
            }
            //shortselling and then rebuying
            else if(type == 2)
            {
                include = -prices[i] + byrec(prices , k-1 , i+1 , 0);
            }
            //neutral transaction
            else 
            {
                ll buy = -prices[i] + byrec(prices , k , i+1 , 1);
                ll shortsell = prices[i] + byrec(prices , k , i+1 , 2);
                include = max(buy , shortsell);
            }
        }

        return max(include , exclude);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        return byrec(prices , k , 0 , 0);
    }
};