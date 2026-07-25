// https://leetcode.com/problems/powx-n

class Solution {
public:
    using ll = long long;

    double myPow(double x, int n) {
        double power = 1;
        ll exp = (n < 0) ? -(ll)n : (ll)n;
        
        if(n < 0) x = 1.0 / x;

        while(exp != 0)
        {
            if(exp & 1) power *= x;
            x *= x;
            exp >>= 1;
        }
        return power;
    }
};