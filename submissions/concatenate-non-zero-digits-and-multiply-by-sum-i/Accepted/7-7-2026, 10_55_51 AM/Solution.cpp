// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i

class Solution {
public:
    using ll = long long;

    long long sumAndMultiply(int n) {
        ll sum = 0;
        string newstr = "";

        while(n > 0)
        {
            if(n % 10 > 0) newstr += (n % 10) + '0';
            sum += n % 10;
            n /= 10;
        }
        reverse(begin(newstr) , end(newstr));
        ll newint = newstr.empty() ? 0 : stoll(newstr);
        return newint * sum;
    }
};