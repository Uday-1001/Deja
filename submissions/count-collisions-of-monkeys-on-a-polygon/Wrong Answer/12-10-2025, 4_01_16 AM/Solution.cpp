// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon

class Solution {
public:
    const int mod = 1e9 + 7;
    long long power(long long base , long long exp)
    {
        long long ans = 1;
        while(exp > 0)
        {
            if(exp & 1) ans = (ans * base) % mod;   
            base = (base * base) % mod;
            exp /= 2;
        }
        return ans;
    }

    int monkeyMove(int n) {
        return power(2 , n) - 2;
    }
};