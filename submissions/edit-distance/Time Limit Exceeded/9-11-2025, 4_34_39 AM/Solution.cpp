// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int solve(string &word1 , string &word2 , int i , int j)
    {
        //base case
        //word1 is smaller and has finished 
        if(i >= word1.size())
        {
            return word2.size() - j;
        }
        //word2 is smaller and has finished
        if(j >= word2.size())
        {
            return word1.size() - i;
;        }

        //ek case hum solve karenge 
        int ans = 0;

        if(word1[i] == word2[j])
        {
            //means matching characters appear ->then simply move ahead and check other characters
            ans = 0 + solve(word1 , word2 , i+1 , j+1); 
        }
        else
        {
            //means the characters didnt match -> then do the operations needed
            int insertion = 1 + solve(word1 , word2 , i , j+1);
            int deletion = 1 + solve(word1 , word2 , i+1 , j);
            int replacement = 1 + solve(word1 , word2 , i+1 , j+1);

            ans = min(insertion , min(deletion , replacement));
        }
    return ans;
    }
    int minDistance(string word1, string word2) {
       return solve(word1 , word2 , 0 , 0);
    }
};