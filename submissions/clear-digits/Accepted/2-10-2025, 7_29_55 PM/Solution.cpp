// https://leetcode.com/problems/clear-digits

class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();

        for(int i = 1; i<n ;i++)
        {
            if(isdigit(s[i]) && isalpha(s[i-1]))
            {
                s.erase(i-1,2);
                i = i-2;
            }
        }
    return s;
    }
};