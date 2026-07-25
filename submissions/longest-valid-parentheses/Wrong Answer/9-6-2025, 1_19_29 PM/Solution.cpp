// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;

        int longest = 0;
        for(auto ch : s)
        {
            if(st.empty() && ch == '(')
            {
                st.push(ch);
            }
            else if(!st.empty() && st.top() == '(' && ch == ')')
            {
                st.pop();
                longest += 2;
            }
            else
            {
                st.push(ch);
            }
        }
    return longest;
    }
};