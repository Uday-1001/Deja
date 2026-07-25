// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // If already equal, return true.

        unordered_map<char, int> hash;

        // Check character frequencies
        for (int i = 0; i < s1.length(); i++) {
            hash[s1[i]]++;
            hash[s2[i]]--;
        }

        // Verify if the character counts are identical
        for (auto it : hash) {
            if (it.second != 0) return false;
        }

        // Identify differing positions
        vector<int> diff;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // The strings can only be made equal by swapping if exactly 2 positions differ
        return (diff.size() == 2 &&
                s1[diff[0]] == s2[diff[1]] &&
                s1[diff[1]] == s2[diff[0]]);
    }
};