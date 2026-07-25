// https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal

class Solution {
public:
    using ll = long long;
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        ll zero_to_one = 0;
        ll one_to_zero = 0;

        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == '0' and t[i] == '1') zero_to_one++;
            else if(s[i] == '1' and t[i] == '0') one_to_zero++;
        }

        ll cost1 = 0 , cost2 = 0 , cost3 = 0;

        //all flipping.
        cost1 = (zero_to_one + one_to_zero) * flipCost;

        //swapping and then flipping the remaining ones.
        ll minpairs = min<ll>(zero_to_one , one_to_zero);
        ll rempairs = max<ll>(zero_to_one , one_to_zero) - minpairs;

        cost2 = (minpairs * swapCost) + (rempairs * flipCost);

        //first swap the pairs , then remains of swapping/2 are elgible for cross and swap , and then the remains of cross and swap are eligible to be flipped. 
        ll crosspairs = rempairs / 2;
        ll rempairs_to_flip = rempairs % 2;

        cost3 = (minpairs * swapCost) + (crosspairs * (crossCost + swapCost)) + (rempairs_to_flip * flipCost);
    
        return min<ll>({cost1 , cost2 , cost3});
    }
};