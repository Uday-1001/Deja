// https://leetcode.com/problems/check-good-integer

class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum1{} , sum2{};

        while(n > 0)
        {
            int digit = n % 10;
            sum1 += digit;
            sum2 += (digit * digit);
            n /= 10;
        }
        return (sum2 - sum1) >= 50;
    }
};