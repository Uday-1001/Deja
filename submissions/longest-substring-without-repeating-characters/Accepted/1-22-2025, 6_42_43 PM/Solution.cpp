// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int maxLength = 0, i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (last_seen.find(s[j]) != last_seen.end()) {
                i = max(last_seen[s[j]] + 1, i);  // Move left pointer to avoid duplicates
            }
            last_seen[s[j]] = j;  // Store the last seen index of the character
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};
