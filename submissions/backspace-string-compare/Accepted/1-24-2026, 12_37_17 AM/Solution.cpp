// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "" , s2 = "";

        for(auto ch : s)
        {
            if(s1.empty() && ch == '#') continue;
            if(ch != '#') s1.push_back(ch);
            else s1.pop_back();
        }

        for(auto ch : t)
        {
            if(s2.empty() && ch == '#') continue;
            if(ch != '#') s2.push_back(ch);
            else s2.pop_back();
        }
    return s1 == s2;
    }
};