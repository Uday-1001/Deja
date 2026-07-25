// https://leetcode.com/problems/remove-k-balanced-substrings

class Solution {
public:

    void helper(stack<pair<char, int>>& st, int &k){
        if(st.top().first == ')' && st.top().second == k){
            // top nikalo -> temp
            auto temp = st.top();
            st.pop();
            // ab new top wala chek karo 
            if(!st.empty() && st.top().first == '(' && st.top().second >= k){
                st.top().second -= k;
                if(st.top().second == 0){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
    }

    string removeSubstring(string s, int k) {
        stack<pair<char, int>> st;

        for(int i = 0; i<s.length(); i++){

            if(!st.empty() && st.top().first == s[i]){
                st.top().second++;
                helper(st, k);
            }
            else{
                st.push({s[i], 1});
                if(k == 1){
                    helper(st, k);
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            int count = st.top().second;
            char ch = st.top().first;
            while(count--){
                ans.push_back(ch);
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};