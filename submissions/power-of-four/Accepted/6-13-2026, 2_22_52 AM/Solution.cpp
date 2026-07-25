// https://leetcode.com/problems/power-of-four

class Solution {
public:
    int BinaryConversion(int n)
    {
        int nullbit = 0;
        while(n > 0)
        {
            if(n % 2 == 0) nullbit++;
            n >>= 1;
        }
        return nullbit;
    }

    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n & 1) return false;

        int setbit = __builtin_popcount(n);
        int nullbits = BinaryConversion(n);

        if(setbit == 1)
        {
            if(nullbits % 2 == 0) return true;
        }
        return false;
    }
};