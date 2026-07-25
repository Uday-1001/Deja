// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int byrec(string text1 , string text2 , int i , int j)
    {
        //base case
        if(i >= text1.size() or j >= text2.size()) return 0;

        //ek case hum solve kar dete hai
        //matching case
        int ans = 0;
        if(text1[i] == text2[j])
        {   
            ans = 1 + byrec(text1 , text2 , i+1 , j+1);
        }
        else 
        {
            //non matching case 
            int op1 = byrec(text1 , text2 , i+1 , j);
            int op2 = byrec(text1 , text2 , i , j+1);

            ans = max(op1 , op2);
        }
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        return byrec(text1, text2 , 0 , 0);
    }
};