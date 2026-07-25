// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;

        int count = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            char ch = s[i];
            if(!st.empty() and st.top() == 'b' and ch == 'a')
            {
                st.pop();
                count++;
            }
            else st.push(ch);
        }
        return count;

        
    }
};