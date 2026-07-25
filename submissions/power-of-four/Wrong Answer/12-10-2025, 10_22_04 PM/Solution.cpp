// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 2) return false;
        else if(n == 1) return true;
        else if(274877906944 % n == 0) return true;
        else return false;
    }
};