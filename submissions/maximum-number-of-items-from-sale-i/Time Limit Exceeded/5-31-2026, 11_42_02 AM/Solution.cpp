// https://leetcode.com/problems/maximum-number-of-items-from-sale-i

class Solution {
public:
    int n;
    vector<int>freecopies;
    vector<vector<int>>dp;

    int byrec(vector<vector<int>>& items , int budget , int i)
    {
        if(i >= n) return 0;
        if(dp[i][budget] != -1) return dp[i][budget];

        int ans = 0;

        int price = items[i][1];

        //take 
        if(budget >= price)
        {
            for(int purchase = 1 ; (purchase * price) <= budget ; purchase++)
            {
                int take = purchase + freecopies[i] + byrec(items , budget - (purchase * price) , i+1);
                ans = max(ans , take);
            }
        }

        // dont take
        int dont_take = byrec(items , budget , i+1);
        ans = max(ans , dont_take);

        return dp[i][budget] = ans;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();

        freecopies.assign(n , 0);
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                int factor = items[j][0];

                if(i != j and (factor % items[i][0] == 0)) freecopies[i]++;
            }
        }

        dp.assign(n+1 , vector<int>(budget + 1 , -1));
    
        return byrec(items , budget , 0);
    }
};