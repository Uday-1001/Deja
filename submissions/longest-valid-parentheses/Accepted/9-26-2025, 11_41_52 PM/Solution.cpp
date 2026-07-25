// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int max_len = 0;

        if(s.length() < 2) return 0;

        for(int i=0 ; i<s.size() ; i++)
        {
            char ch = s[i];

            if(st.empty() && ch == '(')
            {
                st.push(i);
            }
            else if(!st.empty() && st.top() != -1 && s[st.top()] == '(' && ch == ')')
            {
                st.pop();
                max_len = max(max_len , (i - st.top()));
            }
            else
            {
                st.push(i);
            }
        }
    return max_len;
    }
};