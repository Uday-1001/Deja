// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = INT_MIN;
        unordered_map<char,int>mp;
        int r = 0;
        
        while(r < s.size())
        {
            if(mp.count(s[r]))
            {
                mp.erase(s[l]);
                l++;
            }
            else
            {
                mp[s[r]]++;
                ans = max(ans , r - l + 1);
                r++;
            }
        }
    return ans;
    }
};