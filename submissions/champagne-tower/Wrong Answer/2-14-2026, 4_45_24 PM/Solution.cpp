// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double bytab(int query_row , int query_glass , int poured)
    {
        vector<vector<double>>dp(query_row+1 , vector<double>(query_glass+1 , 0.0));

        dp[0][0] = poured;

        for(int i = 1 ; i<=query_row ; i++)
        {
            for(int j = 1 ; j<=query_glass ; j++)
            {
                double left_glass = (dp[i-1][j-1] - 1) / 2.0;
                double right_glass = (dp[i-1][j] - 1) / 2.0;

                if(left_glass < 0) left_glass = 0.0;
                if(right_glass < 0) right_glass = 0.0;

                dp[i][j] = left_glass + right_glass;
            }
        }
    return dp[query_row][query_glass];
    }

    double bymemo(int poured, int i , int j , vector<vector<double>>&dp)
    {
        if(i < 0 or j < 0) return 0.0;
        if(i == 0 and j == 0) return poured;
        if(dp[i][j] != -1) return dp[i][j];

        //ek case hum solve karenge
        double left_glass = (bymemo(poured , i-1 , j-1 , dp) - 1) / 2.0;
        double right_glass = (bymemo(poured , i-1 , j , dp) - 1) / 2.0;

        if(left_glass < 0) left_glass = 0.0;
        if(right_glass < 0) right_glass = 0.0;

        return dp[i][j] = left_glass + right_glass;
    }

    double byrec(int poured, int i , int j)
    {
        //base case
        if(i < 0 or j < 0) return 0.0;
        if(i == 0 and j == 0) return poured;

        //ek case hum solve karenge
        double left_glass = (byrec(poured , i-1 , j-1) - 1) / 2.0;
        double right_glass = (byrec(poured , i-1 , j) - 1) / 2.0;

        if(left_glass < 0) left_glass = 0.0;
        if(right_glass < 0) right_glass = 0.0;

        return left_glass + right_glass;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        // return min(1.0 , byrec(poured , query_row , query_glass));

        // vector<vector<double>>dp(query_row+1 , vector<double>(query_glass+1 , -1));
        // return min(1.0 , bymemo(poured , query_row , query_glass , dp));

        return min(1.0 , bytab(query_row , query_glass , poured));
    }
};