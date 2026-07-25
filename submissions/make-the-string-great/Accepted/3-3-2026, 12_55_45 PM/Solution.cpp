// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        stack<char>st;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(!st.empty() and abs(st.top() - s[i]) == 32)
            {
                st.pop();
            }
            else st.push(s[i]);
        }
        
        if(st.empty()) return "";

        string ans ="";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }   
    reverse(ans.begin() , ans.end());
    return ans;
    }
};