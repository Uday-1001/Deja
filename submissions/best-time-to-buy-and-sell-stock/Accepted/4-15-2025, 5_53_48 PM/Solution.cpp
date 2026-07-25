// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    void recursion(vector<int>& prices , int day , int &minprice , int &maxprofit)
    {
        //base case
        if(day >= prices.size())
            return;

        //ek case hum solve karenge baaki recursion sambhalga
        if(minprice > prices[day])
        {
            minprice = prices[day];
        }
        if((prices[day] - minprice) > maxprofit)
        {
            maxprofit = prices[day] - minprice;
        }

        recursion(prices , day + 1 , minprice , maxprofit);   
    }
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = INT_MIN;

        recursion(prices , 0 , minprice , maxprofit);

        return maxprofit;
    }
};