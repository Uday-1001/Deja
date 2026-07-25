// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<long long, greater<long long>> s;
        vector<int> ans;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                //single cell is also a rhombus
                s.insert(grid[i][j]);

                // Expand the rhombus for different radii
                for (int radius = 1; ; radius++) 
                {
                    int up = i - radius;
                    int down = i + radius;
                    int left = j - radius;
                    int right = j + radius;

                    // Out of bound condition
                    if (up < 0 || down >= n || left < 0 || right >= m) break;

                    long long sum = 0;

                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[up + k][j + k];
                    }
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[i + k][right - k];
                    }
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[down - k][j - k];
                    }
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[i - k][left + k];
                    }

                    s.insert(sum);
                }
            }
        }

        // Extract the top 3 distinct elements from the set
        for (auto val : s) 
        {
            ans.push_back(val);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};