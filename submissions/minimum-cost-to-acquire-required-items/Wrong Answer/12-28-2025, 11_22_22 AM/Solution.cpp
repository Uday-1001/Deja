// https://leetcode.com/problems/minimum-cost-to-acquire-required-items

class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 and need2 == 0) return 0;

        ll min_cost = min<ll>({cost1 , cost2 , costBoth});
        if(min_cost == costBoth) return costBoth * max<ll>(need1 , need2);

        ll total = LLONG_MAX;

        ll op1 = 0 , op2 = 0 , op3 = 0;
        
        op1 = ((cost1 * need1) + (cost2 * need2));

        op2 = ((costBoth * need1) + (cost2 * need2));
    
        op3 = ((cost1 * need1) + (costBoth * need2));
    
        total = min<ll>({total , op1 , op2 , op3});
    
        return total;
    }
};