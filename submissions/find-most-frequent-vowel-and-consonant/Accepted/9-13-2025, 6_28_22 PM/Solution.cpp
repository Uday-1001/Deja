// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;

        for(auto ch: s)
        {
            mp[ch]++;
        }

        int vowel_maxfreq = 0;
        int consonant_maxfreq = 0;

        for(auto it : mp)
        {
            if(it.first == 'a' || it.first == 'e' ||it.first == 'i' ||it.first == 'o' ||it.first == 'u')
            vowel_maxfreq = max(vowel_maxfreq , it.second);

            else
            consonant_maxfreq = max(consonant_maxfreq , it.second);
        }
    return vowel_maxfreq + consonant_maxfreq;
    }
};