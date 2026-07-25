// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
         
        for(auto ch : s)
        {
            while(!st.empty() && ch == ')')
            {
                st.pop();
            }
            st.push(ch);
        }
    return st.size();
    }
};