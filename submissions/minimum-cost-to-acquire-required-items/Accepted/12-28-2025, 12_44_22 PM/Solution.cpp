// https://leetcode.com/problems/minimum-cost-to-acquire-required-items

class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 and need2 == 0) return 0;

        ll min_cost = min<ll>({cost1 , cost2 , costBoth});
        if(min_cost == costBoth) return (ll)costBoth * max<ll>(need1 , need2);

        ll total = 0;
        ll minneed = LLONG_MAX;
        if(((ll)cost1 + (ll)cost2) < costBoth)
        {
            return (((ll)cost1 * need1) + ((ll)cost2 * (ll)need2));
        }       
        minneed = min<ll>(need1 , need2);
        total += (ll)costBoth * minneed;
        need1 -= minneed;
        need2 -= minneed;

        total += (((ll)cost1 * need1) + ((ll)cost2 * need2)) > ((ll)costBoth * max<ll>(need1 , need2)) ? ((ll)costBoth * max<ll>(need1 , need2)) : (((ll)cost1 * need1) + ((ll)cost2 * need2));

        return total;
    }
};