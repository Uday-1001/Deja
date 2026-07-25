// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        int num = 0;

        while(s[i] == ' ') i++;

        if(i < n && (s[i] == '+' or s[i] == '-'))
        {
            sign = s[i] == '+' ? 1 : -1;
            i++; 
        }

        while(i < n && isdigit(s[i]))
        {
            if(num > INT_MAX/10 or (num == INT_MAX/10 and s[i] > '7' ))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return (sign * num);
    }
};