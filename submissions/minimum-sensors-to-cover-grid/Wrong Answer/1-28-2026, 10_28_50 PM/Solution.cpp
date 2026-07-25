// https://leetcode.com/problems/minimum-sensors-to-cover-grid

class Solution {
public:
    int minSensors(int n, int m, int k) {
        int total_cells = n * m;
        int cell_covered = 8 * k+1;

        if(cell_covered >= total_cells) return 1;
        
        return ceil(total_cells / cell_covered);
    }
};