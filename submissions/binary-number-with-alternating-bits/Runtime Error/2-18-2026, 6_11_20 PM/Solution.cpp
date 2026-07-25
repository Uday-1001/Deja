// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n >> 1);
        return x & (x+1) ? false : true;
    }
};