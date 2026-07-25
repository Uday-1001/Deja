// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i = 0; i<s.size() ; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                //checking for the matching pairs of each bracket... if found then remove the opening one from stack
                if(!st.empty() && (s[i] == ')' && st.top() == '('))
                {
                    st.pop();
                }
                else if(!st.empty() && (s[i] == '}' && st.top() == '{'))
                {
                    st.pop();
                }
                else if(!st.empty() && (s[i] == ']' && st.top() == '['))
                {
                    st.pop();
                }
                else 
                    //string is false if it starts with any of the closing brackets
                    return false;
            }
        }
    return (st.empty());
    }
};