// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:

    vector<vector<bool>> mat;
    vector<int> dp;

    void preCalculate(string& s){
        for(int len = 1; len<=s.length(); len++){
            for(int i = 0; i+len-1<s.length(); i++){
                int start = i;
                int end = i + len - 1;
                if(len == 1){
                    mat[start][end] = true;
                }
                else if(len == 2){
                    mat[start][end] = s[start] == s[end];
                }
                else{
                    mat[start][end] = (mat[start+1][end-1] & (s[start] == s[end]));
                }
            }
        }
    }

    bool isPalindrome(string& s){
        int i = 0, j = s.length()-1;
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
            if(mat[i][j]){
                int temp = 1 + solve(s, j+1);
                mini = min(mini, temp);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        dp.resize(s.length()+1, -1);
        mat.resize(2001, vector<bool>(2001, false));
        preCalculate(s);
        int ans = solve(s, 0);
        return ans - 1;
    }
};