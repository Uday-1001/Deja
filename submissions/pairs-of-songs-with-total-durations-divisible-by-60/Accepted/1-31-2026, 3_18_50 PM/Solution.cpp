// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    using ui = unsigned int;
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>count(60 , 0);
        
        for(auto it : time) count[it % 60]++;
        
        ui ans = 0;
        
        ans += (ui)count[0] * (ui)(count[0] - 1) / 2;
        ans += (ui)count[30] * (ui)(count[30] - 1) / 2;
        
        for(int i = 1 ; i<30 ; i++)
        {
            int need = 60 - i;
            ans += (ui)count[i] * (ui)count[need];
        }
    return ans;
    }
};