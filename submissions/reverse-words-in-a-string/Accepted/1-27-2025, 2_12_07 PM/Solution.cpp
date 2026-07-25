// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin() , s.end());
      
        int i=0 ,start=0,end=0;

        for(int i=0 ; i<n; i++)
        {
            while(i<n && s[i] == ' ')
            {
                i++;
            }
            if(i == n)  break;
            while(i<n && s[i] != ' ')
            {
                s[end++] = s[i++];
            }
            reverse(s.begin()+start , s.begin()+end);
            s[end++] = ' ';
            start = end;
            
        }
    s.resize(end-1);
    return s;
    }
};