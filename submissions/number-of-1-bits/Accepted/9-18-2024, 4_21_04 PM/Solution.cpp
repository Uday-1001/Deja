// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0)
        {
            if(n&1)
            {
                count++;
            }
            n=n>>1;
        }
            return count ;        
    }
};