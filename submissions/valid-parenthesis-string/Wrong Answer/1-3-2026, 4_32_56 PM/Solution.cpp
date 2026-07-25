// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int stars = 0 , left = 0 , right = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '*') stars++;
            else if(s[i] == ')') right++;
            else left++;
        }
    return ((left == right) or (abs(right - left) <= stars));
    }
};