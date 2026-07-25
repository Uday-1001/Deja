// https://leetcode.com/problems/minimum-string-length-after-balanced-removals

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<int>st;
        for(int i=0 ; i<s.size() ; i++){
            if(!st.empty() and s[i] == 'a') st.push(s[i]);
            else if(!st.empty() and s[i] == 'b')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};