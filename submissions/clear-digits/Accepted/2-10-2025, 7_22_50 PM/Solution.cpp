// https://leetcode.com/problems/clear-digits

class Solution {
public:
    string clearDigits(string s) {

        for(int i = 1; i<s.size(); i++)
        {
            if(isdigit(s[i]) && isalpha(s[i-1]))
            {
                s.erase(i-1,2);
                i = max(0 , i-2);
            }
        }
    return s;
    }
};