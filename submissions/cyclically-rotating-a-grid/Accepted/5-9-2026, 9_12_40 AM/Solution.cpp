// https://leetcode.com/problems/cyclically-rotating-a-grid

class Solution {
public:
    int n , m;
    vector<vector<int>>arrays;

    void SpiralTraversal(vector<vector<int>>& grid)
    {
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;

        while(top <= bottom && left <= right)
        {
            vector<int> arr;

            for(int i = left ; i<=right ; i++) arr.push_back(grid[top][i]);

            for(int i = top+1 ; i<=bottom ; i++) arr.push_back(grid[i][right]);

            for(int i = right-1 ; i>=left ; i--) arr.push_back(grid[bottom][i]);

            for(int i = bottom-1 ; i>top ; i--) arr.push_back(grid[i][left]);

            arrays.push_back(arr);

            top++;
            bottom--;
            left++;
            right--;
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        SpiralTraversal(grid);

        for(auto &it : arrays)
        {
            int rotation = k % it.size();
            rotate(it.begin(), it.begin() + rotation, it.end());
        }

        vector<vector<int>>ans = grid;

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;

        int layer = 0;

        while(top <= bottom && left <= right)
        {
            int idx = 0;

            for(int i = left ; i<=right ; i++) ans[top][i] = arrays[layer][idx++];

            for(int i = top+1 ; i<=bottom ; i++) ans[i][right] = arrays[layer][idx++];

            for(int i = right-1 ; i>=left ; i--) ans[bottom][i] = arrays[layer][idx++];
           
            for(int i = bottom-1 ; i>top ; i--) ans[i][left] = arrays[layer][idx++];

            top++;
            bottom--;
            left++;
            right--;
            layer++;
        }

        return ans;
    }
};