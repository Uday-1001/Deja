// https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;

        for(int i = 0 ; i<100 ; i++)
        {
            if(abs(n - i) <= k and ((n & i) == 0)) sum += i;
        }
        return sum;
    }
};