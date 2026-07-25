// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        int hash[26] = {0};
        for(int i =0 ; i<s.size(); i++)
        {
            hash[s[i]-'a']++;
        }
        int possible ;
        int count = 0 ;
        for(int i=0 ; i<26 ; i++)
        {
            possible = hash[i] & 1 ? count++ : 0 ;
        }
        
            if(count <= k && s.length() >= k)
            {
                return true;
            }
        return false;
    }
};