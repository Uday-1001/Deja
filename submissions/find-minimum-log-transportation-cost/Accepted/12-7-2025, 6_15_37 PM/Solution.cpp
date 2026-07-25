// https://leetcode.com/problems/find-minimum-log-transportation-cost

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n < k and m < k) return 0;
        long long needed = n > k ? n : m;
        long long cost = 0;
        while(needed > k)
        {
            long long part_cut = needed - k;
            needed = needed - part_cut;
            cost += part_cut * needed;
        }
        return cost;
    }
};