// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:

    void recursion(vector<int>& prices , int i , int &min_price , int&max_profit)
    {
        //base case 
        if(i >= prices.size()) return ;
        
        // hum sirf ek case solve krenge aur recursion sab sambhal lega 
        if(prices[i] < min_price)
        {
            min_price = prices[i];
        }
        if((prices[i] - min_price) > max_profit)
        {
            max_profit = prices[i] - min_price;
        }

        recursion(prices , i+1 , min_price , max_profit);

    }
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = INT_MIN;

        recursion(prices , 0 , min_price , max_profit);
        return max_profit;
    }
};