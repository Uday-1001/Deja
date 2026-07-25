// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k

class Solution {
public:
    const int mod = 1e9+7;

    int bymemo(vector<vector<int>>& grid, int k , int i , int j , int sum , vector<vector<vector<int>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        //base case 
        if(i == n-1 and j == m-1)
        {
            sum = (sum + grid[i][j]) % mod;
            return (sum % k == 0) ? 1 : 0;
        }

        if(dp[i][j][sum % k] != -1) return dp[i][j][sum % k];

        //ek case hum solve karenge 
        int right = 0;
        if(j+1 < m)
        {
            right = bymemo(grid , k , i , j+1 , (sum + grid[i][j]) % mod , dp);
        }

        int down = 0;
        if(i+1 < n)
        {
            down = bymemo(grid , k , i+1 , j , (sum + grid[i][j]) % mod , dp);
        }
           
        return dp[i][j][sum % k] = (right + down) % mod;   
    }

    // int byrec(vector<vector<int>>& grid, int k , int i , int j , long long sum)
    // {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     //base case 
    //     if(i == n-1 and j == m-1)
    //     {
    //         sum = (sum + grid[i][j]) % mod;
    //         if(sum % k == 0) path++;
    //         return 0;
    //     }

    //     //ek case hum solve karenge 
    //     int right = 0;
    //     if(j+1 < m)
    //     {
    //         sum = (sum + grid[i][j]) % mod;
    //         int right = byrec(grid , k , i , j+1 , sum);
    //     }

    //     int down = 0;
    //     if(i+1 < n)
    //     {
    //         sum = (sum + grid[i][j]) % mod;
    //         int down = byrec(grid , k , i+1 , j , sum);
    //     }
           
    //     return right + down;
    // }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // byrec(grid , k , 0 , 0 , 0);

        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(m+1 , vector<int>(k+1 , -1)));
        return bymemo(grid , k , 0 , 0 , 0 , dp);
    }
};