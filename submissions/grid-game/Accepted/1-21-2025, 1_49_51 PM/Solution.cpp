// https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long int top_sum =0;
        int n = grid[0].size();

        for(int i=0 ; i<n ;i++)
        {
            top_sum += grid[0][i];
        }
        long long int bottom_sum=0;
        long long int ans = LONG_MAX;
        for(int p=0 ; p<n ; p++)
        {
            //subtract top value
            //find ans 
            //add bottom value
            top_sum -= grid[0][p];
            ans = min(ans ,(max(top_sum , bottom_sum)));
            bottom_sum += grid[1][p];
        }
    return ans ;
    }
};