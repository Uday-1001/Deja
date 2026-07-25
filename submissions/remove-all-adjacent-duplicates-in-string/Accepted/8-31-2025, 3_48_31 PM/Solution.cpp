// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for(int i=0; i<s.size() ; i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(!st.empty() && (s[i] == st.top()))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string final_ans = "";
        while(!st.empty())
        {
            char top = st.top();
            final_ans += top;
            st.pop();
        }
    reverse(begin(final_ans) , end(final_ans));
    return final_ans;
    }
};