// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    using ll = long long;
    bool isPalindrome(int x) {
        ll rev = 0;
        int y = x;

        while(x > 0)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return y == rev;
    }
};