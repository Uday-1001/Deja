// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    int reverseBits(int n) {
        if(n == 0) return 0;

        int ans = 0;
        for(int i = 1 ; i<=32 ; i++)
        {
            int lsb = n & 1;
            ans <<= 1;
            ans = ans | lsb;
            n >>= 1;
        }
    return ans;
    }
};