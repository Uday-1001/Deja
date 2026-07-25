// https://leetcode.com/problems/count-total-number-of-colored-cells

class Solution {
public:
    long long coloredCells(int n) {
        return (long long)1 + 2*((n*n) - n);
    }
};