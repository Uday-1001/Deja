// https://leetcode.com/problems/minimum-cost-to-acquire-required-items

class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 and need2 == 0) return 0;

        ll min_cost = min<ll>({cost1 , cost2 , costBoth});
        if(min_cost == costBoth) return costBoth * max<ll>(need1 , need2);

        ll total = LLONG_MAX;

        ll op1 = 0 , op2 = 0 , op3 = 0 , op4 = 0;
        
        op1 = ((cost1 * need1) + (cost2 * need2));

        op2 = ((costBoth * need1) + (cost2 * need2));
    
        op3 = ((cost1 * need1) + (costBoth * need2));

        bool type1 = false;
        int remain = 0;
        int maxneed = INT_MIN;
        if(need1 > need2)
        {
            remain += need1 - need2;
            maxneed = max<ll>(maxneed , min<ll>(need1 , need2));
            type1 = true;
        }
        else
        {
            remain += need2 - need1;
            maxneed = max<ll>(maxneed , min<ll>(need1 , need2));
            type1 = false;
        }

        op4 = (costBoth * maxneed);
        op4 += (type1 == true) ? cost1 * remain : cost2 * remain;
    
        total = min<ll>({total , op1 , op2 , op3 , op4});
    
        return total;
    }
};