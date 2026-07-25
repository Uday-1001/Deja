// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};