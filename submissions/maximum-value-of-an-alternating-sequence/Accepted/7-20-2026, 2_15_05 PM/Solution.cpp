// https://leetcode.com/problems/maximum-value-of-an-alternating-sequence

class Solution {
public:
    using ll = long long;
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;

        return (ll)s + (ll)(n/2 * (ll)m) - (ll)(n/2-1);
    }
};