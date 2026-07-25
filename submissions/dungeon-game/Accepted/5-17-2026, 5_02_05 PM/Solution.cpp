// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    vector<vector<int>>dp;

    int solve(vector<vector<int>>& dungeon, int i, int j, int n, int m){
        // base case
        if(i == n-1 && j == m-1){
            int temp = (dungeon[i][j] > 0 ? -dungeon[i][j] : abs(dungeon[i][j]));
            return temp;
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];


        // right 
        int right = INT_MAX;
        if(j + 1 < m){
            right = (dungeon[i][j] > 0 ? -dungeon[i][j] : abs(dungeon[i][j]));
            int rec = solve(dungeon, i, j+1, n, m);
            if(rec < 0){
                // means nahi dena hai -> aage + waale hai
                rec = 0;
            }
            else{
                right += rec;
            }
        }
        // down
        int down = INT_MAX;
        if(i + 1 < n){
            down = (dungeon[i][j] > 0 ? -dungeon[i][j] : abs(dungeon[i][j]));
            int rec = solve(dungeon, i+1, j, n, m);
            if(rec < 0){
                // means nahi dena hai -> aage + waale hai
                rec = 0;
            }
            else{
                down += rec;
            }
        }
        return dp[i][j] = min(right, down);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        dp.assign(n+1 , vector<int>(m+1 , INT_MAX));
        int ans = solve(dungeon, 0, 0, n, m);
        if(ans < 0) return 1;
        return ans + 1;
    }
};