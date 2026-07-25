// https://leetcode.com/problems/word-pattern

class Solution {
public:
    unordered_map<string , char>mp1;
    unordered_map<char , string>mp2;

    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;

        int i = 0;
        while(ss >> word)
        {
            if(i == pattern.size()) return false;
            if(mp1.count(word) and mp1[word] != pattern[i]) return false;
            if(mp2.count(pattern[i]) and mp2[pattern[i]] != word) return false;

            mp1[word] = pattern[i];
            mp2[pattern[i]] = word;
            i++;
        }

        return true;
    }
};