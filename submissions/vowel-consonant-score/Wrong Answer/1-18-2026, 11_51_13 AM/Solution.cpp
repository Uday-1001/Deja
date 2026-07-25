// https://leetcode.com/problems/vowel-consonant-score

class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 0 , conso = 0;
        for(auto it : s)
        {
            if(it == 'a' or it == 'e' or it == 'i' or it == 'o' or it == 'u') vowel++;
            else conso++;
        }

        int score = 0;
        if(conso > 0) score = floor(vowel/conso);
        return score;
    }
};