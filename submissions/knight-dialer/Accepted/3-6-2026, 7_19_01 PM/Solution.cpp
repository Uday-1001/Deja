// https://leetcode.com/problems/knight-dialer

class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>>dp;

    vector<pair<int,int>>moves = 
    { {2,1}, {2,-1}, {-2,1}, {-2,-1},{1,2}, {1,-2}, {-1,2}, {-1,-2}};

    vector<vector<char>>phone = {{'1' , '2' , '3'},
                                 {'4' , '5' , '6'},
                                 {'7' , '8' , '9'},
                                 {'*' , '0' , '#'}};

    bool isValidMove(int i , int j)
    {
        if(i >= 0 and i < 4 and j >= 0 and j < 3 and phone[i][j] != '*' and phone[i][j] != '#')
            return true;
        else 
            return false;
    }

    int byrec(int n , int i , int j , int formed)
    {
        if(formed == n) return 1;
        if(dp[i][j][formed] != -1) return dp[i][j][formed];

        int ans = 0;
        for(int k = 0 ; k<8 ; k++)
        {
            int newi = i + moves[k].first;
            int newj = j + moves[k].second;

            if(isValidMove(newi , newj))
            {
                ans = (ans + byrec(n , newi , newj , formed + 1)) % mod;
            }
        }
        return dp[i][j][formed] = (ans % mod);
    }

    int knightDialer(int n) {
        int ans = 0;

        dp = vector<vector<vector<int>>>(5 , vector<vector<int>>(4 , vector<int>(n+1 , -1)));
        for(int i = 0 ; i<4 ; i++)
        {
            for(int j = 0 ; j<3 ; j++)
            {
                if((i == 3 and j == 0) or (i == 3 and j == 2)) continue;
                ans = (ans + byrec(n , i , j , 1)) % mod;
            }
        }
    return ans % mod;
    }
};