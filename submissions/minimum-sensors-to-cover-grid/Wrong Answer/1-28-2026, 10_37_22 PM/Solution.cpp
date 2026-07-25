// https://leetcode.com/problems/minimum-sensors-to-cover-grid

class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s = (2*k + 1);

        if(s > n and s > m) return 1;
        return ceil(n / s) * ceil(m / s);
    }
};