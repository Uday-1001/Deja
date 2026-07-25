// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool IsValidParentheses(string &s){
        int n = s.length();

        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty() && s[i] == ')' && st.top() == '(')
                {
                      st.pop(); 
                }    
                else
                {
                    return false;
                }
            }
        }
    if(st.empty()) return true;
        return false;  
}

    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n & 1) return false;
        bool possible = true;
        if(n == 2){
            if(s[1]==')') s[1] ='(';
            if(s[2]=='(') s[2] =')';
            possible = true;
        }

        for(int i=0 ; i<n ; i++)
        {
            if(locked[i] == '0')
            {
                if(s[n-1] == '(') s[i] = ')';
                if(s[i+1] == ')') s[i] = '(';
                possible = IsValidParentheses(s);   
            }
        }
    if(possible)
    {
        return true ;
    }
    return false;
    }    
};