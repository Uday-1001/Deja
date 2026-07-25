// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        string n = "1";

        if(k % 2 == 0 or k % 5 == 0) return -1;

        while(true)
        {
            long long num = stoll(n);
            if(num % k == 0) break;
            else
            n.push_back('1');
        }
    return n.size();
    }
};