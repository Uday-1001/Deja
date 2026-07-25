// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long num = 0;

        //omit all the leading spaces
        while(s[i] == ' ')
        {
            i++;
        }
        //next character should be a sign
        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        } 
        //next character should strictlybe a digit
        while(i < n && isdigit(s[i]))
        {
            //the overflow case and underflow case should be handled with care
            if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7'))
            {
                num = sign == -1 ? INT_MIN : INT_MAX;
            } 
            num = num * 10 + (s[i] - '0');
            i++;
        }
    return (num * sign); 
    }
};