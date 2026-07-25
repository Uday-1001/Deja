// https://leetcode.com/problems/minimum-bitwise-or-from-grid

class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        unordered_set<int>dp;
        dp.insert(0);

        for(auto &it : grid){
            unordered_set<int>nextdp;
            for(auto prevval : dp){
                for(auto x : it){
                    nextdp.insert(prevval | x);
                }
            }
            dp = nextdp;
        }
        int ans = INT_MAX;
        for(auto it : dp){
            ans = min(ans, it);
        }
        return ans;
    }
};