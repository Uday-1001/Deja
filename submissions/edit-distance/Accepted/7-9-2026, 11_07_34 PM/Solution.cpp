// https://leetcode.com/problems/edit-distance

class Solution {
public: 
    vector<vector<int>>dp;

    int byrec(string word1 , string word2 , int i , int j)
    {
        //base case 
        if(i >= word1.size()) return word2.size() - j;
        if(j >= word2.size()) return word1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        if(word1[i] == word2[j]) 
        {
            int matched = 0 + byrec(word1 , word2 , i+1 , j+1);
            ans = min(ans , matched);
        }
        else
        {
            int replacement = 1 + byrec(word1, word2 , i+1 , j+1);
            int deletion = 1 + byrec(word1, word2 , i , j+1);
            int insertion = 1 + byrec(word1, word2 , i+1 , j);
            ans = min({ans , replacement , deletion , insertion});
        }

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        dp.assign(n+1 , vector<int>(m+1 , -1));
        return byrec(word1 , word2 , 0 , 0);
    }
};