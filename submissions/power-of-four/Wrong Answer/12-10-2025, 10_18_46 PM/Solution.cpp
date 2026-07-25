// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n != 2 and (274877906944 % n == 0 or n == 1);
    }
};