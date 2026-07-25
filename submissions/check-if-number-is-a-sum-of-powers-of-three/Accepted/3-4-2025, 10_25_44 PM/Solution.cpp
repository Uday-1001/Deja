// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0)
        {
            int quotient = n / 3;
            int remainder = n % 3;
            if(remainder == 2 or quotient == 2)
            return false;
            n = quotient;
        }
        return true;
    }
};