// https://leetcode.com/problems/maximum-number-of-items-from-sale-i

class Solution {
public:
    int n;
    vector<int>freecopies;

    int byrec(vector<vector<int>>& items , int budget , int i)
    {
        if(i >= n) return 0;

        int ans = 0;

        int price = items[i][1];

        //take 
        if(budget >= price)
        {
            for(int purchase = 1 ; purchase * price <= budget ; purchase++)
            {
                ans = max(ans , purchase + freecopies[i] + byrec(items , budget - (purchase * price) , i+1));
            }
        }

        // dont take
        ans = max(ans , byrec(items , budget , i+1));
        return ans;
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

        return byrec(items , budget , 0);
    }
};