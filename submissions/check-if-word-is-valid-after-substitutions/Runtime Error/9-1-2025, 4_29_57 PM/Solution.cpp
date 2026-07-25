// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0 ; i<s.size() ; i++)
        {
            if(st.empty() && s[i] == 'a')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && (st.top() == 'a' && s[i] == 'b'))
            {
                st.push(s[i]);
            }
            else if(!st.empty() && (st.top() == 'b' && s[i] == 'c'))
            {
                st.pop();
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    return (st.empty());
    }
};