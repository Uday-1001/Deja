// https://leetcode.com/problems/last-stone-weight-ii

class Solution {
public:
    int solve(vector<int>& stones, int i, int currSum , vector<vector<int>>&dp) 
    {
        if(i == stones.size()) return abs(currSum);
        if(dp[i][currSum + 3000] != -1) return dp[i][currSum + 3000];

        int op1 = solve(stones, i + 1, currSum + stones[i] , dp);
        
        int op2 = solve(stones, i + 1, currSum - stones[i] , dp);
        
        return dp[i][currSum + 3000] = min(op1 , op2);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        
        vector<vector<int>>dp(n+1 , vector<int>(6000+1 , -1));
        return solve(stones, 0, 0 , dp);
    }
};
