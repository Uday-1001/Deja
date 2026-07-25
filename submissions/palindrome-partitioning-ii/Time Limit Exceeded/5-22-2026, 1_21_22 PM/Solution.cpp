// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool isPalindrome(string &s , int i , int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int solve(string &s , int i , int j , vector<vector<int>>&dp){
        // base case
        if(i >= j) return 0;
        if(isPalindrome(s , i , j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // the MCM format process
        int mini = INT_MAX;
        for(int k = i ; k<j ; k++)
        {
            int temp = 1 + solve(s , i , k , dp) + solve(s , k+1 , j , dp);
            mini = min(mini , temp);
        }
        return dp[i][j] = mini;
    }

    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1 , vector<int>(s.size()+1 , -1));

        int ans = solve(s , 0 , s.size()-1 , dp);
        return ans;
    }
};