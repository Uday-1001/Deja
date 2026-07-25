// https://leetcode.com/problems/first-matching-character-from-both-ends

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        int index = -1;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == s[n-i-1]) return i;
        }
        return -1;
    }
};