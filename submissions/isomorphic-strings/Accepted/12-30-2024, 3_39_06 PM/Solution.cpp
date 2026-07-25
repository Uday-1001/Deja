// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        // Iterate through the strings
        for(int i = 0; i < s.size(); i++) {
            // If character from s is encountered for the first time, store its index
            if(m1.find(s[i]) == m1.end()) 
                m1[s[i]] = i;
            // If character from t is encountered for the first time, store its index
            if(m2.find(t[i]) == m2.end()) 
                m2[t[i]] = i;

            // Check if current mappings have the same indexes stored 
            if(m1[s[i]] != m2[t[i]]) 
                return false;
        }

        return true;
    }
};