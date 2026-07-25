// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,int> hash1(26);
        unordered_map<char,int> hash2(26);

        for(int i =0 ; i<n ; i++)
        {
            hash1[s[i]] = i;
            hash2[t[i]] = i;
        }
        for(int i =0; i<n ;i++)
        {
            if(hash1[s[i]] != hash2[t[i]])
            {
                return false;
            }
        }
    return true;
    }
};