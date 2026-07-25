// https://leetcode.com/problems/maximum-value-of-an-alternating-sequence

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        
        return s + (n/2 * m) - (n/2-1);
    }
};