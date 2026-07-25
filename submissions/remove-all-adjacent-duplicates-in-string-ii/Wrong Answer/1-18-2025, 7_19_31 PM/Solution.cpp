// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
          string result; // This will act as our stack-like structure
        vector<int> counts; // To keep track of character counts in the string
        
        for (char c : s) {
            // If the result is not empty and the last character matches the current one
            if (!result.empty() && result.back() == c) {
                counts.back()++; // Increment the count for the last character
                // If the count reaches k, remove the character from result and counts
                if (counts.back() == k) {
                    result.pop_back(); // Remove the character from the result
                    counts.pop_back(); // Remove the corresponding count from counts
                }
            } else {
                result.push_back(c); // Add the character to the result
                counts.push_back(1); // Initialize its count as 1
            }
        }
        
        return result; // Return the modified string
    }
    
};