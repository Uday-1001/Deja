// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int bb=prices[0];
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]>bb){
                mp= max(mp,prices[i]-bb);   
            }
            else{ mp=0; }
        
            bb= min(bb, prices[i]);
        }
         return mp;
    }
};