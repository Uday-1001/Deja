// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int n, m;

    int solve(int i, int j, vector<vector<int>>& dungeon)
    {
        if(i >= n or j >= m) return 1e8;

        if(i == n-1 and j == m-1)
        {
            if(dungeon[i][j] <= 0) return abs(dungeon[i][j]) + 1;
            else return 1;
        }

        int right = solve(i , j + 1 , dungeon);
        int down = solve(i + 1 , j , dungeon);

        int need = min(right , down) - dungeon[i][j];

        return (need <= 0) ? 1 : need;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        return solve(0, 0, dungeon);
    }
};
