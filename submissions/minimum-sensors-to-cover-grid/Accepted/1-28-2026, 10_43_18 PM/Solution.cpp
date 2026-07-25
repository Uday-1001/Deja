// https://leetcode.com/problems/minimum-sensors-to-cover-grid

class Solution {
public:
    int minSensors(int n, int m, int k) {
        double block = 2.0 * k + 1.0;

        int rows = (int)ceil(n / block);
        int cols = (int)ceil(m / block);

        return rows * cols;

    }
};