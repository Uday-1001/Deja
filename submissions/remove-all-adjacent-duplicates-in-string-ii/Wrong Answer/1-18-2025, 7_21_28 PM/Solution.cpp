// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string result; // This will act as our stack-like structure
        vector<int> counts; // To keep track of character counts in the string
        
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                // If last character matches, increment the count
                counts.back()++;
                
                // If count reaches k, pop the last character and count
                if (counts.back() == k) {
                    result.pop_back(); // Remove the character
                    counts.pop_back(); // Remove the corresponding count
                }
            } else {
                result.push_back(c); // Add new character to result
                counts.push_back(1); // Initialize count for new character
            }
        }
        
        return result; // Return the resulting string
    }
};

