// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs) , end(costs));

        int icecreams = 0;
        int cost = 0;
        for(auto it : costs)
        {
            cost += it;
            if(cost <= coins) icecreams++;
        }
        return icecreams;
    }
};