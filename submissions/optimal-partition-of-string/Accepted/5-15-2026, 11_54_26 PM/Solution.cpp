// https://leetcode.com/problems/optimal-partition-of-string

class Solution {
public:
    int partitionString(string s) {
        int parts = 0;
        unordered_map<char,int>mp;

        for(int r = 0; r<s.size() ; r++)
        {
            char ch = s[r];
            if(mp.count(ch)) 
            {
                parts++;
                mp.clear();
            }
            mp[ch]++;
        }
        return parts + 1;
    }
};