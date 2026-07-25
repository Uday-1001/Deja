// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k

class Solution {
public:
    const int mod = 1e9+7;
    int path = 0;
    int byrec(vector<vector<int>>& grid, int k , int i , int j , long long sum)
    {
        int n = grid.size();
        int m = grid[0].size();
        //base case 
        if(i == n-1 and j == m-1)
        {
            sum += grid[i][j];
            if(sum % k == 0) path++;
            return 0;
        }

        //ek case hum solve karenge 
        int right = 0;
        if(j+1 < m)
            int right = byrec(grid , k , i , j+1 , sum + grid[i][j]);

        int down = 0;
        if(i+1 < n)
            int down = byrec(grid , k , i+1 , j , sum + grid[i][j]);

        return right + down;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        path = 0;
        byrec(grid , k , 0 , 0 , 0);
        return path;
    }
};