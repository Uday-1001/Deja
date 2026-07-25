// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    //Couldn't Understand Lakshya's Code so took help of Gemini
    //Gemini generated code , not mine...
    //Just checking for the correctness of the code 
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Use a set to automatically handle distinct sums and sorting.
        set<int> sums;

        // Iterate over every possible center (r, c)
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                
                // --- Case k = 0 ---
                // The rhombus is just the cell itself.
                sums.insert(grid[r][c]);

                // --- Case k > 0 ---
                // k is the "radius" or distance from the center to a corner.
                for (int k = 1; ; ++k) {
                    
                    // Define the four corners
                    int r_up = r - k;
                    int r_down = r + k;
                    int c_left = c - k;
                    int c_right = c + k;

                    // Boundary Check: If any corner is out of bounds,
                    // this k (and all larger k) are invalid for this center.
                    if (r_up < 0 || r_down >= m || c_left < 0 || c_right >= n) {
                        break; 
                    }

                    // Calculate the sum of the border
                    int current_sum = 0;

                    // 1. Top-right edge (from top corner to cell before right corner)
                    for (int i = 0; i < k; ++i) {
                        current_sum += grid[r_up + i][c + i];
                    }
                    
                    // 2. Bottom-right edge (from right corner to cell before bottom corner)
                    for (int i = 0; i < k; ++i) {
                        current_sum += grid[r + i][c_right - i];
                    }
                    
                    // 3. Bottom-left edge (from bottom corner to cell before left corner)
                    for (int i = 0; i < k; ++i) {
                        current_sum += grid[r_down - i][c - i];
                    }
                    
                    // 4. Top-left edge (from left corner to cell before top corner)
                    for (int i = 0; i < k; ++i) {
                        current_sum += grid[r - i][c_left + i];
                    }
                    
                    // Add the total border sum to our set
                    sums.insert(current_sum);
                }
            }
        }
        
        // Convert the set (which is sorted ascending) to a vector
        // using reverse iterators to get descending order.
        vector<int> result(sums.rbegin(), sums.rend());

        // Resize the vector to be at most 3 elements
        if (result.size() > 3) {
            result.resize(3);
        }
        
        return result;
    }
};