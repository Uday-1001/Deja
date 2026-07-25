// https://leetcode.com/problems/minimum-length-of-string-after-operations

class Solution {
public:
    int minimumLength(string s) {
        int n = s. length();
        int hash[26] = {0};
        if(n <=2)
        {
            return n;
        }
        for(int i =0 ; i<s.size(); i++)
        {
            hash[s[i]-'a']++;
        }

        int count = 0;

        for(int i =0 ; i<26 ; i++)
        {
            if(hash[i]>0)
            {  
                count += hash[i] & 1 ? 1 : 2;
            }     
        }
        return count ;
    }
};