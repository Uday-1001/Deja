// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int bytab(string text1 , string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = m-1 ; j >= 0 ; j--)
            {
                //matching case
                if(text1[i] == text2[j])
                {   
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else 
                {
                    //non matching case 
                    int op1 = dp[i+1][j];
                    int op2 = dp[i][j+1];
                    dp[i][j] = max(op1 , op2);
                }
            }
        }
    return dp[0][0];
    }

    int byrec(string text1 , string text2 , int i , int j , vector<vector<int>>&dp)
    {
        //base case
        if(i >= text1.size() or j >= text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        //ek case hum solve kar dete hai
        //matching case
        int ans = 0;
        if(text1[i] == text2[j])
        {   
            ans = 1 + byrec(text1 , text2 , i+1 , j+1 , dp);
        }
        else 
        {
            //non matching case 
            int op1 = byrec(text1 , text2 , i+1 , j , dp);
            int op2 = byrec(text1 , text2 , i , j+1 , dp);

            ans = max(op1 , op2);
        }
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // return byrec(text1, text2 , 0 , 0 , dp);

        return bytab(text1 , text2);
    }
};