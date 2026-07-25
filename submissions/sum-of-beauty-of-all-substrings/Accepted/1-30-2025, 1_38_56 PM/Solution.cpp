// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.length();

        // Iterate over all possible substrings
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            
            for (int j = i; j < n; j++) {
                // Update frequency of current character
                freq[s[j]]++;

                // Find max and min frequency in current substring
                int maxFreq = INT_MIN, minFreq = INT_MAX;
                for (auto& entry : freq) {
                    maxFreq = max(maxFreq, entry.second);
                    minFreq = min(minFreq, entry.second);
                }

                // Add the beauty (max - min) to total sum
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};