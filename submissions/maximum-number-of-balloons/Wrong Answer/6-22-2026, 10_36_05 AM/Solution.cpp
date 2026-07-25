// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>hash(26 , 0);

        for(auto it : text) hash[it - 'a']++;
        int words_formed = 0;
        int partsofword = 0;

        for(int i = 0 ; i<26 ; i++)
        {
            char ch = i + 'a';
            if(hash[ch - 'a'] <= 0) continue;

            if(ch == 'b') partsofword++;
            if(ch == 'a') partsofword++;
            if(ch == 'l' and hash[ch - 'a'] >= 2) partsofword++;
            if(ch == 'o' and hash[ch - 'a'] >= 2) partsofword++;
            if(ch == 'n') partsofword++;

            if(partsofword == 5)
            {
                words_formed++;
                hash[0]--;
                hash[1]--;
                hash[11] -= 2;
                hash[15] -= 2;
                hash[14]--;
            }
        }
        return words_formed;
    }
};