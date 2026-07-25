// https://leetcode.com/problems/gcd-of-odd-and-even-sums

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd((n * n) , (n * (n+1)));
    }
};