// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream ss(s);

        string ans = "";
        vector<string>words;

        while(ss >> word) words.push_back(word);

        for(int i = words.size() - 1 ; i >= 0 ; i--)
        {
            ans += words[i];
            if(i != 0) ans += ' ';
        }

        return ans;
    }
};