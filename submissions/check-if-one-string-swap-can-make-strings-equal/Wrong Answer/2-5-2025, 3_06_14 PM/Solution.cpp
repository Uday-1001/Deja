// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        unordered_map<char,int> hash;

        for(int i = 0 ; i < s1.size() ;i++)
        {
            hash[s1[i] - 'a']++;
            hash[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26 ;i++)
        {
            if(hash[i] !=0) return false;
        }
        return true;
    }
};