// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLength = 0, i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (lastIndex.find(s[j]) != lastIndex.end()) {
                i = max(lastIndex[s[j]] + 1, i);  // Move left pointer to avoid duplicates
            }
            lastIndex[s[j]] = j;  // Store the last seen index of the character
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};
