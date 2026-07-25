// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int byrec(string text1, string text2, int i , int j)
    {
        //base case
        if(i >= text1.size() or j >= text2.size()) return 0;
    
        //ek case hum solve karenge 
        int ans_str = 0;
        //matching case
        if(text1[i] == text2[j])
        {
            ans_str = 1 + byrec(text1 , text2 , i+1 , j+1);
        }
        else
        {
            //not matching case
            int option1 = 0 + byrec(text1 , text2 , i+1 , j);
            int option2 = 0 + byrec(text1 , text2 , i , j+1);
            ans_str = max(option1 , option2);
        }
        return ans_str;
    }

    int longestCommonSubsequence(string text1, string text2) {
        return byrec(text1 , text2 , 0 , 0);
    }
};