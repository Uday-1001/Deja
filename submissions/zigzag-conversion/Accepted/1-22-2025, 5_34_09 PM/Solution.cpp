// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int row=0 , i=0;
        bool direction = 1;

        vector<string> zigzag(numRows);
        if(numRows == 1) return s;

        while(i<s.size())
        {
            if(direction == 1)
            {
                while(i<s.size() && row < numRows)
                {
                    zigzag[row++].push_back(s[i++]);
                }
                row = row-2;
            }
            else
            {
                while(i<s.size() && row >= 0)
                {
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            direction = !direction;
        }
        string ans = "";
        for(auto str : zigzag)
        {
            ans += str;
        }
    return ans ;
    }
};