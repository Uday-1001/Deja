// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int countones = 0;
        int countzeros = 0;
        int ans = 0;

        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == '1')
            {
                if(countzeros > 0)
                {
                    countzeros--;
                    countones++;
                    ans++;
                }
                else countones++;
            }
            else if(s[i] == '0')
            {
                if(countones > 0)
                {
                    countones--;
                    countzeros++;
                    ans++;
                }
                else countzeros++;
            }
        }
    return ans;
    }
};