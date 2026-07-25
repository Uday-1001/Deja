// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    using ll = long long;

    int CheckAllConditions(string &s)
    {
        int i = 0;
        int n = s.size();

        ll number_formed = 0;
        int sign = 1;
        
        while(i < n and s[i] == ' ') i++;

        if(i == n) return 0;

        if(s[i] == '-' or s[i] == '+')
        {
            sign = (s[i] == '-') ? -1 : +1;
            i++;
        }

        while(i < n and isdigit(s[i])) 
        {
            number_formed = number_formed * 10 + (s[i] - '0');

            if(sign == 1 and number_formed > INT_MAX) return INT_MAX;
            if(sign == -1 and -number_formed < INT_MIN) return INT_MIN;
            i++;
        }

        return number_formed * sign;
    }

    int myAtoi(string s) {
        return CheckAllConditions(s);
    }
};