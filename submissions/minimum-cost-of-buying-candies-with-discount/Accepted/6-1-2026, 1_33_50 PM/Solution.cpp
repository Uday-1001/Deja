// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(begin(cost) , end(cost));

        int total = 0;
        for(int i = n-1 ; i>=0 ; i-=3)
        {
            total += cost[i];
            total += ((i-1 >= 0) ? cost[i-1] : 0);
        }
        return total;
    }
};