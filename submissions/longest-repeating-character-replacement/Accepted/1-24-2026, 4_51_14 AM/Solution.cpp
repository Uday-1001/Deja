// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        int l = 0;
        int maxlen = 0;
        int maxfreq = 0;

        for(int r = 0 ; r<n ; r++)
        {
            mp[s[r]]++;
            maxfreq = max(maxfreq , mp[s[r]]);
            int len = r - l + 1;
            int to_change = len - maxfreq;
            
            //shrinking the window
            if(to_change > k) mp[s[l++]]--;

            //updating the length when valid
            if(to_change <= k) maxlen = max(maxlen , len);
        }
    return maxlen;
    }
};