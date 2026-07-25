// https://leetcode.com/problems/last-remaining-integer-after-alternating-deletion-operations

class Solution {
public:
    using ll = long long;
    long long lastInteger(long long n) {
        ll start = 1;
        ll steps = 1;
        bool left = true;

        while(n > 1)
        {
            if(!left and (n % 2 == 0)) start += steps;
            n = n & 1 ? n/2 + 1 : n/2;
            steps *= 2;
            left = !left;
        }
    return start;
    }
};