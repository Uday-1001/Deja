// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mapping;
        
        int start = 0;
        int len = 1;
        
        if(s == "") return 0;

        for(int j = 0 ;j<s.size() ;j++)
        {
            if(mapping.find(s[j]) != mapping.end())
            {
                start = max(start , mapping[s[j]] + 1);
            }
            mapping[s[j]] = j;
            len = max (len , j-start+1);
        }
    return len;
    }
};