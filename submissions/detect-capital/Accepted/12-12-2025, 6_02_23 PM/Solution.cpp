// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        int capitals = 0;
        int lower = 0;

        for(int i=0 ; i<word.size() ; i++)
        {
            if(islower(word[i])) lower++;
            else capitals++;
        }
        return ((capitals == len) or (lower == len) or (isupper(word[0]) and lower == len - 1));
    }
};