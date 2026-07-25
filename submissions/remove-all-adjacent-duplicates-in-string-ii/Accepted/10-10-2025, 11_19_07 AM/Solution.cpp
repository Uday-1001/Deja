// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push({s[0], 1});
        for(int i = 1; i<s.length(); i++){
            if(!st.empty() && st.top().first == s[i]){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push({s[i], 1});
            }
        }
        string ans = "";
        while(!st.empty()){
            int count = st.top().second;
            char ch = st.top().first;
            st.pop();
            while(count--){
                ans.push_back(ch);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};