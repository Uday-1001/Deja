// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int bb=prices[0];
        for(int i=1;i<prices.size();i++){
            //compare and find for profit 
            if(prices[i]>bb){
                mp= max(mp,prices[i]-bb);   
            }
            //selecting the best price of the stock
            bb= min(bb, prices[i]);
        }
         return mp;
    }
};