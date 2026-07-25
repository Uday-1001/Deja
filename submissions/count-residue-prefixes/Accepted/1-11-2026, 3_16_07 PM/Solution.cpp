// https://leetcode.com/problems/count-residue-prefixes

class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        set<char>st;
        vector<string>pref(s.size());
        pref[0] = s[0];

        for(int i =1 ; i<n ; i++) pref[i] = pref[i-1] + s[i];

        int count = 0;
        for(int i =0 ; i<n ; i++)
        {
            string s = pref[i];
            for(auto it : s) st.insert(it);
            if(st.size() == (s.size() % 3))
            {
                count++;
                st.clear();
            } 
        }
    return count;
    }
};