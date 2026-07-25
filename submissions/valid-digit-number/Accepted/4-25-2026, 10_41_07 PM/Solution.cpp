// https://leetcode.com/problems/valid-digit-number

class Solution {
public:
    bool validDigit(int n, int x) {
        set<int>st;
        int m = n;

        while(n > 0)
        {
            st.insert(n % 10);
            n /= 10;
        }

        string num = to_string(m);
        if(st.count(x) and (num[0] - '0' != x)) return true;
        return false;
    }
};