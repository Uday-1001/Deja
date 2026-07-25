// https://leetcode.com/problems/minimum-string-length-after-balanced-removals

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<pair<int,int>>st;
        int count = 1;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(!st.empty() and s[i] == st.top().first)
            {
                st.top().second++;
            }
            else if(!st.empty() and s[i] != st.top().first)
            {
                if(st.top().second == 1) st.pop();
                else 
                    st.top().second--;
                count = 1;
            }
            else
                st.push({s[i] , count++});
        }
    return st.size() == 1 ? st.top().second : st.size();
    }
};