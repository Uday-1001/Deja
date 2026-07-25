// https://leetcode.com/problems/last-stone-weight-ii

class Solution {
public:
    int ans = INT_MAX;

    void solve(vector<int>& stones, int i, int currSum) 
    {
        if(i == stones.size()) 
        {
            ans = min(ans, abs(currSum));
            return;
        }

        solve(stones, i + 1, currSum + stones[i]);

        solve(stones, i + 1, currSum - stones[i]);
    }

    int lastStoneWeightII(vector<int>& stones) {
        solve(stones, 0, 0);
        return ans;
    }
};
