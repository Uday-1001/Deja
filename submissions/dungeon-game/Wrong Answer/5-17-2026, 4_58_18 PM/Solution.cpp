// https://leetcode.com/problems/dungeon-game

class Solution {
public:

    int solve(vector<vector<int>>& dungeon, int i, int j, int n, int m){
        // base case
        if(i == n-1 && j == m-1){
            int temp = (dungeon[i][j] > 0 ? -dungeon[i][j] : abs(dungeon[i][j]));
            return temp;
        }


        // right 
        int right = INT_MAX;
        if(j + 1 < m){
            right = (dungeon[i][j] > 0 ? -dungeon[i][j] : abs(dungeon[i][j]));
            int rec = solve(dungeon, i, j+1, n, m);
            if(rec == 0){
                right++;
            }
            else if(rec < 0){
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
            if(rec == 0){
                down++;
            }
            else if(rec < 0){
                // means nahi dena hai -> aage + waale hai
                rec = 0;
            }
            else{
                down += rec;
            }
        }
        return min(right, down);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int ans = solve(dungeon, 0, 0, n, m);
        return ans + 1;
    }
};