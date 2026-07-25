// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    int minFlips(string s) {
        int minflips = INT_MAX;

        int size = s.size();
        for(int k = 0 ; k < size ; k++)
        {
            int pattern_zero = 0, pattern_one = 0;

            for(int i = 0; i < size; i++) 
            {
                char ch = s[(i + k) % size];
                if(i % 2 == 0) 
                {
                    if(ch != '0') pattern_zero++;  
                    if(ch != '1') pattern_one++;   
                }
                else 
                {
                    if(ch != '1') pattern_zero++;
                    if(ch != '0') pattern_one++;
                }
            }
            minflips = min(minflips , (min(pattern_zero, pattern_one)));
        }
    return minflips;
    }
};