// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mapping;

        int maxlen = INT_MIN;
        int len = 1;

        for(int j = 0 ; j<s.size() ; j++)
        {
            char ch = s[j];
            if(mapping.find(ch) != mapping.end())
            {
                mapping.clear();
                mapping[ch] = j;
                len = 1;
            }
            mapping[s[j]] = j;
            maxlen = max(maxlen , len);
            len++;
        }
    return maxlen;
    }
};