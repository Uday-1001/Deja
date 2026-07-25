// https://leetcode.com/problems/number-of-paths-with-max-score

class Solution {
public:
    using vi = vector<int>;
    int mod = 1e9+7;

    vi byrec(vector<string>& board , int i , int j)
    {
        if(i < 0 or j < 0 or board[i][j] == 'X') return {-1 , 0};
        if(i == 0 and j == 0) return {0 , 1};

        vi up = byrec(board , i-1 , j);
        vi left = byrec(board , i , j-1);
        vi upleft = byrec(board , i-1 , j-1);

        int bestval = max({up[0] , left[0] , upleft[0]});

        if(bestval == -1) return {-1 , 0};

        int bestpath = 0;

        if(up[0] == bestval) bestpath = (bestpath + up[1]) % mod;
        if(left[0] == bestval) bestpath = (bestpath + left[1]) % mod;
        if(upleft[0] == bestval) bestpath = (bestpath + upleft[1]) % mod;

        if(board[i][j] != 'S' and board[i][j] != 'E')
        {
            bestval += board[i][j] - '0';
        }

        return {bestval , bestpath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        vi ans = byrec(board , board.size()-1 , board.size()-1);

        if(ans[0] == -1) return {0 , 0};

        return ans;
    }
};