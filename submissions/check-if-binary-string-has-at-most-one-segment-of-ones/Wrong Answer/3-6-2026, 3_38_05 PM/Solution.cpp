// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size() == 1) if(s[0] == '1') return true;

        for(int i = 1 ; i<s.size() ; i++) if(s[i] == '1' and s[i-1] == '1') return true;
        
    return false;
    }
};