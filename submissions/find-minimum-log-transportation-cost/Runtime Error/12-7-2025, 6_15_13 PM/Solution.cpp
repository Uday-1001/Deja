// https://leetcode.com/problems/find-minimum-log-transportation-cost

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n < k and m < k) return 0;
        int needed = n > k ? n : m;
        int cost = 0;
        while(needed > k)
        {
            int part_cut = needed - k;
            needed = needed - part_cut;
            cost += part_cut * needed;
        }
        return cost;
    }
};