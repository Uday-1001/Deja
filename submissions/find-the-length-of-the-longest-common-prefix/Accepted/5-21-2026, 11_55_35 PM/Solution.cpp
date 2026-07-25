// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        for(auto it : arr1)
        {
            string s = "";
            string num = to_string(it);
            for(auto ch : num)
            {
                s += ch;
                st.insert(s);
            }
        }

        int ans = INT_MIN;
        for(auto it : arr2)
        {
            string s = "";
            string num = to_string(it);
            for(auto ch : num)
            {
                s += ch;
                int len = s.size();
                if(st.count(s)) ans = max(ans , len);
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};