// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxlen = 0;
        int max_freq = 0;
        vector<int>hash(26 , 0);

        for(int r=0 ; r<s.size() ; r++)
        {
            hash[s[r] - 'A']++;
            max_freq = max(max_freq , hash[s[r] - 'A']);
            int changes = (r-l+1) - max_freq;

            if(changes > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }

            if(changes <= k)
            {
                maxlen = max(maxlen , r-l+1);
            }
        }
    return maxlen;
    }
};