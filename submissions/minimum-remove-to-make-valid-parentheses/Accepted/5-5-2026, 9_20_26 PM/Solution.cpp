// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;

        for(int i = 0 ; i<s.size() ; i++)
        {
            char ch = s[i];
            if(ch == '(') open++;
            else if(ch == ')') close++;
            else continue;

            if(open < close) 
            {
                s[i] = '#';
                close--;
            }
        }       

        open = 0 , close = 0;
        for(int i = s.size()-1 ; i>=0 ; i--)
        {
            char ch = s[i];
            if(ch == '(') open++;
            else if(ch == ')') close++;
            else continue;

            if(close < open) 
            {
                s[i] = '#';
                open--;
            }
        }

        string ans = "";
        for(auto it : s) if(it != '#') ans.push_back(it);

        return ans;
    }
};