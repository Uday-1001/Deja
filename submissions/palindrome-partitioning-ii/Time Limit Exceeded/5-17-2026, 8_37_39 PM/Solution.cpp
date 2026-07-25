// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:

    vector<int> dp;

    bool isPalindrome(string& s , int start ,int end){
        int i = start, j = end;
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    int solve(string s, int i){
        // base case
        if(i >= s.length()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        // processing
        int mini = INT_MAX;
        for(int j = i; j<s.length(); j++){
            if(isPalindrome(s,i,j)){
                int temp = 1 + solve(s, j+1);
                mini = min(mini, temp);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        dp.resize(s.length()+1, -1);
        int ans = solve(s, 0);
        return ans - 1;
    }
};