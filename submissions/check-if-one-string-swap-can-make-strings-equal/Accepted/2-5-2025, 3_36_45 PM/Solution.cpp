// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        vector<int>pos;
        for(int i = 0 ; i < s1.size() ;i++)
        {
            if(s1[i] != s2[i])
            pos.push_back(i);
        }

    return ( pos.size()==2 && 
            s1[pos[0]] == s2[pos[1]] && 
            s1[pos[1]] == s2[pos[0]] );
    }
};