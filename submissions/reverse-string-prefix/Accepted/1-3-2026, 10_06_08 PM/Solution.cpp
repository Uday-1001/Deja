// https://leetcode.com/problems/reverse-string-prefix

class Solution {
public:
    string reversePrefix(string s, int k) {
        if(k == s.size())
        {
            reverse(s.begin() , s.end());
            return s;
        }
        
        string ans = "";
        string rev = s.substr(0 , k);
        reverse(rev.begin() , rev.end());
        ans += rev;
        ans += s.substr(k);
        return ans;
    }
};