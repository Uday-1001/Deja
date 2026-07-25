// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    int minFlips(string s) {
        string doubled = s + s;
        int n = doubled.size();

        int pattern_one = 0 , pattern_zero = 0;

        for(int i = 0 ; i<n ; i++)
        {
            if(i % 2 == 0)
            {
                if(s[i] != '0') pattern_zero++;
                if(s[i] != '1') pattern_one++;
            }
            else 
            {}
        }
    }
};