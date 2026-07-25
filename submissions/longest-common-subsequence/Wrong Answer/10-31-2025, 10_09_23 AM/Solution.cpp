// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int byspace_op2(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<int>curr(m+1 , 0);

        for(int i =n-1 ; i>=0 ; i--)
        {
            for(int j=m-1 ; j>=0 ; j--)
            {
                int ans_str = 0;
                //matching case
                if(text1[i] == text2[j])
                {
                    ans_str = 1 + curr[j+1];
                }
                else
                {
                    //not matching case
                    int option1 = 0 + curr[j+1];
                    int option2 = 0 + curr[j];
                    ans_str = max(option1 , option2);
                }
                curr[j] = ans_str;
            }
            // next = curr;
        }
    return curr[0];
    }

    // int byspace_op1(string text1, string text2)
    // {
    //     int n = text1.size();
    //     int m = text2.size();

    //     vector<int>curr(m+1 , 0);
    //     vector<int>next(m+1 , 0);

    //     for(int i =n-1 ; i>=0 ; i--)
    //     {
    //         for(int j=m-1 ; j>=0 ; j--)
    //         {
    //             int ans_str = 0;
    //             //matching case
    //             if(text1[i] == text2[j])
    //             {
    //                 ans_str = 1 + next[j+1];
    //             }
    //             else
    //             {
    //                 //not matching case
    //                 int option1 = 0 + curr[j+1];
    //                 int option2 = 0 + next[j];
    //                 ans_str = max(option1 , option2);
    //             }
    //             curr[j] = ans_str;
    //         }
    //         next = curr;
    //     }
    // return curr[0];
    // }

    // int bytab(string text1, string text2)
    // {
    //     int n = text1.size();
    //     int m = text2.size();

    //     vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

    //     for(int i =n-1 ; i>=0 ; i--)
    //     {
    //         for(int j=m-1 ; j>=0 ; j--)
    //         {
    //             int ans_str = 0;
    //             //matching case
    //             if(text1[i] == text2[j])
    //             {
    //                 ans_str = 1 + dp[i+1][j+1];
    //             }
    //             else
    //             {
    //                 //not matching case
    //                 int option1 = 0 + dp[i+1][j];
    //                 int option2 = 0 + dp[i][j+1];
    //                 ans_str = max(option1 , option2);
    //             }
    //             dp[i][j] = ans_str;
    //         }
    //     }
    // return dp[0][0]; 
    // }

    // int bymemo(string text1, string text2, int i , int j , vector<vector<int>>&dp)
    // {
    //     //base case
    //     if(i >= text1.size() or j >= text2.size()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];
    
    //     //ek case hum solve karenge 
    //     int ans_str = 0;
    //     //matching case
    //     if(text1[i] == text2[j])
    //     {
    //         ans_str = 1 + bymemo(text1 , text2 , i+1 , j+1 , dp);
    //     }
    //     else
    //     {
    //         //not matching case
    //         int option1 = 0 + bymemo(text1 , text2 , i+1 , j , dp);
    //         int option2 = 0 + bymemo(text1 , text2 , i , j+1 , dp);
    //         ans_str = max(option1 , option2);
    //     }
    //     return dp[i][j] = ans_str;
    // }

    // int byrec(string text1, string text2, int i , int j)
    // {
    //     //base case
    //     if(i >= text1.size() or j >= text2.size()) return 0;
    
    //     //ek case hum solve karenge 
    //     int ans_str = 0;
    //     //matching case
    //     if(text1[i] == text2[j])
    //     {
    //         ans_str = 1 + byrec(text1 , text2 , i+1 , j+1);
    //     }
    //     else
    //     {
    //         //not matching case
    //         int option1 = 0 + byrec(text1 , text2 , i+1 , j);
    //         int option2 = 0 + byrec(text1 , text2 , i , j+1);
    //         ans_str = max(option1 , option2);
    //     }
    //     return ans_str;
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // return byrec(text1 , text2 , 0 , 0);

        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // return bymemo(text1 , text2 , 0 , 0 , dp);

        // return bytab(text1 , text2);

        // return byspace_op1(text1 , text2);

        return byspace_op2(text1 , text2);
    }
};