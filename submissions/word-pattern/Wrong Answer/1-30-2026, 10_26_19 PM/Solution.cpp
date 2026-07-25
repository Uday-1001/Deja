// https://leetcode.com/problems/word-pattern

class Solution {
public:
    unordered_map<string , int>mp1;
    unordered_map<char , int>mp2;

    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;

        while(ss >> word) mp1[word]++;
        for(auto ch : pattern) mp2[ch]++;

        return mp1.size() == mp2.size();
    }
};