// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string test = s + s;
        string trimmed = test.substr(1 , test.size()-2);
        return trimmed.find(s) != string::npos;
    }
};