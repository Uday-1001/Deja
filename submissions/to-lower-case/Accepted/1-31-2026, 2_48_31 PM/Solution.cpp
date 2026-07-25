// https://leetcode.com/problems/to-lower-case

class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0 ; i<s.size() ; i++)
        {
            char ch = s[i];
            if(isupper(ch)) s[i] = tolower(ch);
        }
        return s;
    }
};