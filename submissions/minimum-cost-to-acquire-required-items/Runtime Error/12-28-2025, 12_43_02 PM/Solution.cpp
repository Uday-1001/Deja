// https://leetcode.com/problems/minimum-cost-to-acquire-required-items

class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 and need2 == 0) return 0;

        ll min_cost = min<ll>({cost1 , cost2 , costBoth});
        if(min_cost == costBoth) return costBoth * max<ll>(need1 , need2);

        ll total = 0;
        ll minneed = LLONG_MAX;
        if((cost1 + cost2) < costBoth)
        {
            return ((cost1 * need1) + (cost2 * need2));
        }       
        minneed = min<ll>(need1 , need2);
        total += costBoth * minneed;
        need1 -= minneed;
        need2 -= minneed;

        total += ((cost1 * need1) + (cost2 * need2)) > (costBoth * max<ll>(need1 , need2)) ? (costBoth * max<ll>(need1 , need2)) : ((cost1 * need1) + (cost2 * need2));

        return total;
    }
};