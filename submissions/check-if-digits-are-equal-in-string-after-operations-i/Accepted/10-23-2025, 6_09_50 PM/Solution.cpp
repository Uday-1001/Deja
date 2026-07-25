// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

class Solution {
public:
    bool hasSameDigits(string s) {
        string ans = "";

        int i = 0;
        while(s.size()>2 && i < s.size()-1)
        {
            ans += (s[i] + s[i+1]) % 10;
            i++;

            if(i == s.size()-1)
            {
                s = ans;
                i = 0;
                ans = "";
            }
        }
        return s.size() == 2 && (s[0] == s[1]);
    }
};