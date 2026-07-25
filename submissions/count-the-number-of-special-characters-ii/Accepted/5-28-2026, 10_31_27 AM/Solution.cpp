// https://leetcode.com/problems/count-the-number-of-special-characters-ii

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26 , -1);
        vector<int>upper(26 , -1);

        int n = word.size();

        for(int i = 0 ; i<n ; i++)
        {
            if(islower(word[i]))
            {
                lower[word[i] - 'a'] = i;
            }
        }

        for(int i = n-1 ; i>=0 ; i--)
        {
            if(isupper(word[i]))
            {
                upper[word[i] - 'A'] = i;
            }
        }

        int count = 0;

        for(int i = 0 ; i<26 ; i++)
        {
            if(lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i])
            {
                count++;
            }
        }

        return count;
    }
};