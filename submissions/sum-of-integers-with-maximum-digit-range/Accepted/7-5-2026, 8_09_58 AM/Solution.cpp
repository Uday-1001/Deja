// https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range

class Solution {
public:
    int digitrange(int x)
    {
        int mx = 0 , mn = 9;
        while(x){
            int d = x % 10;
            mx = max(mx , d);
            mn = min(mn , d);
            x /= 10;
        }
        return mx - mn;
    }
    
    int maxDigitRange(vector<int>& nums) {
        int maxrange = 0;
        for(auto it : nums){
            maxrange = max(maxrange , digitrange(it));
        }
        int sum = 0;
        for(auto it : nums){
            if(digitrange(it) == maxrange) sum += it;
        }
        return sum;
    }
};