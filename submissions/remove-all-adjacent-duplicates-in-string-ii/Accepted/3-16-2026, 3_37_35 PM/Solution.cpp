// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    using pi = pair<char , int>;
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pi>st;

        for(int i = 0 ; i<n ; i++)
        {
            if(!st.empty() and st.top().first == s[i])
            {
                st.top().second++;
                if(st.top().second == k) st.pop();
            }
            else st.push({s[i] , 1});
        }

        string ans = "";
        while(!st.empty())
        {
            auto[ch , freq] = st.top();
            st.pop();
            while(freq--) ans.push_back(ch);
        }
    reverse(begin(ans) , end(ans));
    return ans;
    }
};