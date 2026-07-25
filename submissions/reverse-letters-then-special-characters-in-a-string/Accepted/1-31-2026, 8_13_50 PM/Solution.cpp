// https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string

class Solution {
public:
    string reverseByType(string s) {
        vector<char>letters , special;

        for(int i = 0 ; i<s.size() ; i++){
            char ch = s[i];
            if(ch >= 'a' and ch <= 'z') letters.push_back(s[i]);
            else special.push_back(s[i]);
        }

        reverse(letters.begin() , letters.end());
        reverse(special.begin() , special.end());

        int a = 0 , b = 0;
        for(int i = 0 ; i<s.size() ; i++){
            char ch = s[i];
            if(ch >= 'a' and ch <= 'z') s[i] = letters[a++];
            else s[i] = special[b++];
        }
        return s;

    }
};