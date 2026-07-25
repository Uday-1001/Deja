// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 and 274877906944 % n == 0;
    }
};