// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    bool isSafe(int i , int j , int& n , int& m , vector<vector<bool>>&visited , vector<vector<char>>& grid)
    {
        if(i>=n || j>=m || i<0 || j<0 || visited[i][j] == true || grid[i][j] == '0')
        {
            return false;
        }
    return true;
    }

    void solve(int i , int j , int& n , int& m , vector<vector<bool>>&visited , vector<vector<char>>& grid)
    {
        visited[i][j] = true;
        //up
        if(isSafe(i-1 , j ,  n , m , visited , grid))
        {
            solve(i-1 , j , n , m , visited , grid);
        }
        //down
        if(isSafe(i+1 , j ,  n , m , visited , grid))
        {
            solve(i+1 , j , n , m , visited , grid);
        }
        //right
        if(isSafe(i , j+1 ,  n , m , visited , grid))
        {
            solve(i , j+1 , n , m , visited , grid);
        }
        //left
        if(isSafe(i , j-1 ,  n , m , visited , grid))
        {
            solve(i , j-1 , n , m , visited , grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n , vector<bool>(m , false));

        int ans = 0;

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == false)
                {
                    solve(i , j , n , m , visited , grid);
                    ans++;
                }
            }
        }
    return ans;
    }
};