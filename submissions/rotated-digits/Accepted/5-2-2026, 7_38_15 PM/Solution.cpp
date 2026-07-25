// https://leetcode.com/problems/rotated-digits

class Solution {
public:
    bool getgood(int num)
    {
        unordered_set<int>st;
        while(num > 0)
        {
            int digit = num % 10;
            if(digit == 3 or digit == 4 or digit == 7) return false;
            st.insert(digit);
            num /= 10;
        }
        if(st.count(2) or st.count(5) or st.count(6) or st.count(9)) return true;
        else return false;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            if(getgood(i)) ans++;
        }
        return ans;
    }
};