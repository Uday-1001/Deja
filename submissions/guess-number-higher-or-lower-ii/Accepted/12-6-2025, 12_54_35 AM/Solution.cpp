// https://leetcode.com/problems/guess-number-higher-or-lower-ii

class Solution {
public:
    int bytab(int start , int end , int n)
    {
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        for(int start = n ; start>=1 ; start--)
        {
            for(int end = 1 ; end<=n ; end++)
            {
                if(start >= end) continue;
                else
                {
                    int ans = INT_MAX;
                    for(int i=start ; i<end ; i++)
                    {                    
                        int lower_path = dp[start][i-1];
                        int higher_path = dp[i+1][end];

                        ans = min(ans , i + max(lower_path , higher_path));
                    }   
                    dp[start][end] = ans;
                }
            }
        }
    return dp[1][n];
    }

    // int bymemo(int start , int end , vector<vector<int>>&dp)
    // {
    //     if(start >= end) return 0;
    //     if(dp[start][end] != -1) return dp[start][end];

    //     //ek case hum solve karenge
    //     int ans = INT_MAX;
    //     for(int i=start ; i<end ; i++)
    //     {
    //         int lower_path = bymemo(start , i-1 , dp);
    //         int higher_path = bymemo(i+1 , end , dp);

    //         ans = min(ans , i + max(lower_path , higher_path));
    //     }   
    // return dp[start][end] = ans;
    // }

    // int byrec(int start , int end)
    // {
    //     //base case 
    //     if(start >= end) return 0;

    //     //ek case hum solve karenge
    //     int ans = INT_MAX;
    //     for(int i=start ; i<end ; i++)
    //     {
    //         int lower_path = byrec(start , i-1);
    //         int higher_path = byrec(i+1 , end);

    //         ans = min(ans , i + max(lower_path , higher_path));
    //     }   
    // return ans;
    // }

    int getMoneyAmount(int n) {
        // return byrec(1 , n);

        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return bymemo(1 , n , dp);

        return bytab(1 , n , n);
    }
};