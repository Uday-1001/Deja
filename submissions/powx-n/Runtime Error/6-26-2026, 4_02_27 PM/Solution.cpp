// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        double power = 1;
        long long exp = abs(n);
        
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