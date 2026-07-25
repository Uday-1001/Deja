// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l{};
        int maxlen{};
        unordered_map<char , int>mp;

        for(int r = 0 ; r<s.size() ; r++)
        {
            mp[s[r]]++;

            while(mp[s[r]] > 1) 
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen , r - l + 1);
        }
        return maxlen;
    }
};