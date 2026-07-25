// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0

class Solution {
public:
    int minOperations(int n) {
        vector<int>pow;
        for(int i = 0; (1 << i) <= 2 * n; i++) pow.push_back(1 << i);
        
        int ans = 0;
        while(n > 0)
        {
            int closest = pow[0];

            for(int p : pow){
                if(abs(n - p) < abs(n - closest))
                closest = p;
            }
            n = abs(n - closest);
            ans++; 
        }
        return ans;
    }
};