// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int solve(string &word1, string &word2 , int i , int j)
    {
        //base case 
        if(i >= word1.size()) return word2.size() - j;
        if(j >= word2.size()) return word1.size() - i;

        int ans = 0;
        if(word1[i] == word2[j])
        {
            ans  = 0 + solve(word1 , word2 , i+1 , j+1);
        }
        else
        {
            int insert = 1 +  solve(word1 , word2 , i , j+1);

            int remove = 1 +  solve(word1 , word2 , i+1 , j);
            
            int replace = 1 +  solve(word1 , word2 , i+1 , j+1);

            ans = min(insert , min(remove , replace));
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        
        return solve(word1 , word2 , 0 , 0);
    }
};