// https://leetcode.com/problems/count-total-number-of-colored-cells

class Solution {
public:
    long long coloredCells(int n) {
        long long num = (long long) n*(n-1);
        long long mul = (long long)2* num;
        return 1 + mul;
    }
};