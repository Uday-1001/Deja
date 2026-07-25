// https://leetcode.com/problems/number-of-digit-one

class Solution {
public:
    int dp[11][2][11];
    int digitdp(int index , bool restricted , int count , string &s)
    {
        //base case 
        if(index >= s.size()) return count;

        if(dp[index][restricted][count] != -1) return dp[index][restricted][count];

        //ek case hum solve karenge
        int limit = (restricted == true) ? (s[index]-'0') : 9;

        int ans = 0;
        for(int i = 0 ; i<=limit ; i++)
        {
            int updated_count = count + (i == 1 ? 1 : 0);
            int new_restriction = restricted & ((i == s[index] - '0') ? true : false);

            ans += digitdp(index + 1 , new_restriction , updated_count , s);
        }

        return dp[index][restricted][count] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        int index = 0;
        bool restricted = true;
        int count = 0;

        memset(dp , -1 , sizeof(dp));
        return digitdp(index , restricted , count , s);
    }
};