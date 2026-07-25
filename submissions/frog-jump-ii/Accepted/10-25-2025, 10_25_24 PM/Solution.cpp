// https://leetcode.com/problems/frog-jump-ii

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int max_diff = INT_MIN;

        if(stones.size() == 2) return abs(stones[1] - stones[0]);

        if(n & 1)
        {
            for(int i=2 ; i<n ; i+=2)
            {
                int diff = abs(stones[i-2] - stones[i]);
                max_diff = max(max_diff , diff);
            }
            for(int i=n-2 ; i>1 ; i-=2)
            {
                int diff = abs(stones[i] - stones[i-2]);
                max_diff = max(max_diff , diff);
            }
        }
        else
        {
            for(int i=2 ; i<=n-2; i+=2)
            {
                int diff = abs(stones[i-2] - stones[i]);
                max_diff = max(max_diff , diff);
            } 
            for(int i=n-1 ; i>1 ; i-=2)
            {
                int diff = abs(stones[i] - stones[i-2]);
                max_diff = max(max_diff , diff);
            }
        }
    return max_diff;
    }
};