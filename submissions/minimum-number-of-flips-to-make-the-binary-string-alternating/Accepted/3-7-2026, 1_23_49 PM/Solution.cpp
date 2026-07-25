// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    int minFlips(string s) {
        string doubled = s + s;
        int n = doubled.size();
        int minflips = INT_MAX;

        int pattern_one = 0 , pattern_zero = 0;

        for(int i = 0 ; i<n ; i++)
        {
            if(i % 2 == 0)
            {
                if(doubled[i] != '0') pattern_zero++;
                if(doubled[i] != '1') pattern_one++;
            }
            else 
            {
                if(doubled[i] != '1') pattern_zero++;
                if(doubled[i] != '0') pattern_one++;
            }

            if(i >= s.size())
            {
                int pos = (i - s.size());
                if(pos % 2 == 0)
                {
                    if(doubled[pos] != '0') pattern_zero--;
                    if(doubled[pos] != '1') pattern_one--;
                }
                else 
                {
                    if(doubled[pos] != '1') pattern_zero--;
                    if(doubled[pos] != '0') pattern_one--;
                }
            }

            if(i >= s.size())
            {
                minflips = min(minflips , min(pattern_one , pattern_zero));
            }
        }
    return minflips;
    }
};