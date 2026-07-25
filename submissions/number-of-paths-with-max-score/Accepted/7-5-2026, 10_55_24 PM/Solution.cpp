// https://leetcode.com/problems/number-of-paths-with-max-score

class Solution {
public:
    using pi = pair<int,int>;
    int mod = 1e9+7;

    vector<vector<pi>> dp;

    pi byrec(vector<string>& board , int i , int j)
    {
        if(i < 0 or j < 0 or board[i][j] == 'X') return {-1 , 0};
        if(i == 0 and j == 0) return {0 , 1};

        if(dp[i][j].first != -2) return dp[i][j];

        pi up = byrec(board , i-1 , j);
        pi left = byrec(board , i , j-1);
        pi upleft = byrec(board , i-1 , j-1);

        int bestval = max({up.first , left.first , upleft.first});

        if(bestval == -1) return dp[i][j] = {-1 , 0};

        int bestpath = 0;

        if(up.first == bestval) bestpath = (bestpath + up.second) % mod;
        if(left.first == bestval) bestpath = (bestpath + left.second) % mod;
        if(upleft.first == bestval) bestpath = (bestpath + upleft.second) % mod;

        if(board[i][j] != 'S' and board[i][j] != 'E')
        {
            bestval += board[i][j] - '0';
        }

        return dp[i][j] = {bestval , bestpath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        dp.assign(n, vector<pi>(m, {-2, -2}));

        pi ans = byrec(board , n-1 , m-1);

        if(ans.first == -1) return {0 , 0};

        return {ans.first , ans.second};
    }
};