// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int solve(vector<int>&nums)
    {
        pair<int,int>min_price_with_date = {INT_MAX , INT_MAX};
        for(int i = 0 ; i<nums.size(); i++) 
        {
            min_price_with_date = min(min_price_with_date , {nums[i] , i});
        }

        pair<int,int>max_price_with_date = {INT_MIN , INT_MIN};
        for(int i = nums.size()-1 ; i>min_price_with_date.second; i--) 
        {
            max_price_with_date = max(max_price_with_date , {nums[i] , i});
        }

        if(max_price_with_date.second > min_price_with_date.second)
        {
            return max_price_with_date.first - min_price_with_date.first;
        }

        return 0;
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};