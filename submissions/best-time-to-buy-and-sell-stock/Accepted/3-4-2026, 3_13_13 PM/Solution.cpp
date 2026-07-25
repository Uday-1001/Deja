// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    void solve(vector<int>&prices , int day , int &min_price , int &max_profit)
    {
        //base case 
        if(day>=prices.size()) return ;
        
        //ek case hum solve karenge
        if(min_price > prices[day])
        {
            min_price = prices[day];
        }
        int profit = prices[day] - min_price;
        if(max_profit < profit)
        {
            max_profit = profit;
        }
        solve(prices , day+1 , min_price , max_profit);
        
    }
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = INT_MIN;
        
        solve(prices , 0 , min_price , max_profit);
        return max_profit;
    }
};