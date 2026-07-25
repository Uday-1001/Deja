// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack to keep track of characters and their counts
        vector<pair<char, int>> stack;

        // Process each character in the string
        for (char c : s) {
            // If the stack is not empty and the last character matches the current character
            if (!stack.empty() && stack.back().first == c) {
                // Increment the count of the last character in the stack
                stack.back().second++;
                // If the count reaches k, remove the character from the stack
                if (stack.back().second == k) {
                    stack.pop_back();
                }
            } else {
                // If it's a new character, push it with a count of 1
                stack.push_back({c, 1});
            }
        }

        // Build the final string from the stack
        string result = "";
        for (auto& p : stack) {
            result.append(p.second, p.first);  // Append the character `p.first` `p.second` times
        }

        return result;
    }
};
