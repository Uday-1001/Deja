// https://leetcode.com/problems/maximum-path-score-in-a-grid

class Solution {
public:
    int n , m;
    // vector<vector<vector<int>>>dp;

    int bytab(vector<vector<int>>&grid , int k)
    {
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(m+1 , vector<int>(k+1 , INT_MIN)));

        for(int cost = 0 ; cost<=k ; cost++)
        {
            int to_add = (grid[n-1][m-1] == 0 ? 0 : 1);
            if(to_add + cost <= k) dp[n-1][m-1][cost] = grid[n-1][m-1];
        }

        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = m-1 ; j>=0 ; j--)
            {
                if(i == n-1 and j == m-1) continue;

                for(int cost = k ; cost>=0 ; cost--)
                {
                    int right_score = INT_MIN , down_score = INT_MIN;

                    int newcost = cost + (grid[i][j] == 0 ? 0 : 1);
                    if(newcost > k) continue;

                    if(j+1 < m)
                    {
                        int temp = dp[i][j+1][newcost];
                        if(temp != INT_MIN) right_score = grid[i][j] + temp;
                    }
                    if(i+1 < n)
                    {
                        int temp = dp[i+1][j][newcost];
                        if(temp != INT_MIN) down_score = grid[i][j] + temp;
                    }

                    dp[i][j][cost] = max(right_score , down_score);
                }
            }
        }
        return dp[0][0][0];
    }

    // int byrec(int i , int j , int cost , vector<vector<int>>& grid , int k)
    // {
    //     if(i >= n or j >= m) return INT_MIN;

    //     int newcost = cost + (grid[i][j] == 0 ? 0 : 1);
    //     if(newcost > k) return INT_MIN;

    //     if(i == n-1 and j == m-1) return grid[i][j];

    //     if(dp[i][j][newcost] != INT_MIN) return dp[i][j][newcost];

    //     int right_score = INT_MIN , down_score = INT_MIN;
       
    //     if(j+1 < m)
    //     {
    //         int temp = byrec(i , j+1 , newcost , grid , k);
    //         if(temp != INT_MIN) right_score = grid[i][j] + temp;
    //     }
    //     if(i+1 < n)
    //     {
    //         int temp = byrec(i+1 , j , newcost , grid , k);
    //         if(temp != INT_MIN) down_score = grid[i][j] + temp;
    //     }

    //     return dp[i][j][newcost] = max(right_score , down_score);
    // }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        // dp.assign(n+1 , vector<vector<int>>(m+1 , vector<int>(k+1 , INT_MIN)));

        // int ans = byrec(0 , 0 , 0 , grid , k);
        // return (ans == INT_MIN) ? -1 : ans;

        int ans = bytab(grid , k);
        return (ans == INT_MIN) ? -1 : ans;
    }
};