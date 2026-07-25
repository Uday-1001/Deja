// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start =0;
        int end =0;
        int i = 0;

        reverse(s.begin() , s.end());

        while(i<s.size())
        {
            while(i<n && s[i] == ' ') 
            {
                i++;
            }
            if(i == n) break;

            while(i<n && s[i] != ' ')
            {
                s[end] = s[i];
                end++; i++;
            }
            reverse(s.begin() + start , s.begin() + end);

            s[end] = ' ';
            end++;

            start = end;
            i++;
        } 
    s.resize(end-1); 
    return s;
    } 
};