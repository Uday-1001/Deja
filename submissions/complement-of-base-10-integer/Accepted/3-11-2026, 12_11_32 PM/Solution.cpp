// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        int power = 0;
        int ans = 0;

        if(n == 0) return 1;
        
        while(n > 0)
        {
            int digit = n % 2;
            ans += (digit == 1) ? 0 : pow(2 , power);
            power++;
            n /= 2;
        }
    return ans;
    }
};