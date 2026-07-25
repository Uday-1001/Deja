// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    int minFlips(string s) {
        int minflips = INT_MAX;

        int size = s.size();
        int index = 0;
        for(int i = 0 ; i<(size/2)+1 ; i++)
        {
            int n = s.size();
            char firstchar = s[index];

            int pattern_zero = 0, pattern_one = 0;

            for(int i = index; i < n; i++) 
            {
                if(i % 2 == 0) 
                {
                    if(s[i] != '0') pattern_zero++;  
                    if(s[i] != '1') pattern_one++;   
                }
                else 
                {
                    if(s[i] != '1') pattern_zero++;
                    if(s[i] != '0') pattern_one++;
                }
            }
            minflips = min(minflips , (min(pattern_zero, pattern_one)));
            s.push_back(firstchar);
            index++;
        }
    return minflips;
    }
};