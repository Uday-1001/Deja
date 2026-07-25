// https://leetcode.com/problems/resulting-string-after-adjacent-removals

class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        
        for(int i =0 ; i < s.size(); i++)
        {
            if(!st.empty() and (abs(st.top() - s[i]) == 1))
            {
                st.pop();
            }
            else if(!st.empty() and ((st.top() == 'z' and s[i] == 'a') or (st.top() == 'a' and s[i] == 'z')))
            {
                st.pop();
            }
            else
            st.push(s[i]);
        }
        string ans = "";
        if(st.empty()) return ans;
        else 
        {
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin() , ans.end());
        }
        return ans;
    }
};