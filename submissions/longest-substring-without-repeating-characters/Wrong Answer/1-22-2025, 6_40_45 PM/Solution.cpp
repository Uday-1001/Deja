// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charIndex[256] = {-1};  // Initialize all to -1 (not seen)
        int maxLength = 0, i = 0;
        if(s.size() == 1 ||s == " ") return 1;

        for (int j = 0; j < s.length(); j++) {
            if (charIndex[s[j]] != -1) {
                i = max(charIndex[s[j]] + 1, i);  // Move left pointer to skip duplicate
            }
            charIndex[s[j]] = j;  // Update character position
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};
