// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>count(60 , 0);
        
        for(auto it : time) count[it % 60]++;
        
        int ans = 0;
        
        ans += count[0] * (count[0] - 1) / 2;
        ans += count[30] * (count[30] - 1) / 2;
        
        for(int i = 1 ; i<30 ; i++)
        {
            int need = 60 - i;
            ans += count[i] * count[need];
        }
    return ans;
    }
};