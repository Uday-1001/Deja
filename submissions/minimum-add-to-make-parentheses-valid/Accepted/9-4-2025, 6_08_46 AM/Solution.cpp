// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
         
        for(auto ch : s)
        {
            if(!st.empty() && ch == ')' && st.top() == '(')
            {
                st.pop();
            }
            else st.push(ch);
        }
    return st.size() == 0 ? 0 : st.size();
    }
};