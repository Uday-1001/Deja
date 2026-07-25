// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int n , m;
    int byrec(vector<vector<int>>& obstacleGrid , int i , int j)
    {
        if(i >= m or j >= n or obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;

        int down = byrec(obstacleGrid , i+1 , j);
        int right = byrec(obstacleGrid , i , j+1);

        return down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return byrec(obstacleGrid , 0 , 0);
    }
};