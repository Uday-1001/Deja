// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        string n = "1";
        if(k % 2 == 0) return -1;
        while(true)
        {
            int num = stoi(n);
            if(num % k == 0) break;
            else
            n.push_back('1');
        }
    return n.size();
    }
};