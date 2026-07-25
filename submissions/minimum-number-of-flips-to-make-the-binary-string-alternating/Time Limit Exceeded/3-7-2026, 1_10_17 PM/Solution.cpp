// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:

    int getminoprs(string &s , int start , int end)
    {
        int zeroStart = 0;
        int oneStart = 0;

        for(int i = start ; i < end ; i++)
        {
            int pos = i - start;

            if(pos % 2 == 0)
            {
                if(s[i] != '0') zeroStart++;
                if(s[i] != '1') oneStart++;
            }
            else
            {
                if(s[i] != '1') zeroStart++;
                if(s[i] != '0') oneStart++;
            }
        }
        return min(zeroStart , oneStart);
    }

    int minFlips(string s) {

        string doubled = s + s;
        int k = s.size();

        int minflips = INT_MAX;

        for(int start = 0 ; start < k ; start++)
        {
            int end = start + k;

            minflips = min(minflips , getminoprs(doubled , start , end));
        }

        return minflips;
    }
};