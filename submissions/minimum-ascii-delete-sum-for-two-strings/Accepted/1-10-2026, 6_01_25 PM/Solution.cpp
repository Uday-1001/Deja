// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int bytab(string &s1 , string &s2 , vector<vector<int>>&dp)
    {
        int n = s1.size();
        int m = s2.size();

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = m-1 ; j >= 0 ; j--)
            {
                //matching case
                if(s1[i] == s2[j])
                {   
                    dp[i][j] = s1[i] + dp[i+1][j+1];
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

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        int ans1 = 0 , ans2 = 0;
        for(char it : s1) ans1 += it;
        for(char it : s2) ans2 += it;

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
        int sum = bytab(s1 , s2 , dp);
        return (ans1 - sum) + (ans2 - sum);
    }
};