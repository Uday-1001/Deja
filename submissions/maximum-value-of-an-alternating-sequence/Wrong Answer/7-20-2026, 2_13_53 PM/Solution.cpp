// https://leetcode.com/problems/maximum-value-of-an-alternating-sequence

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        return s + (n/2 * m) - (n/2-1);
    }
};