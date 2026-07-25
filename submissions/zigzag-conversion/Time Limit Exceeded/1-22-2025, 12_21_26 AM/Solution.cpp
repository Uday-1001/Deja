// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int row = 0;
        int i =0;
        bool direction = 1;
        vector<string> ans(numRows);

        while(i < s.size())
        {
            if(direction == 1)
            {
                while(row < numRows && i<s.size())
                {
                    ans[row].push_back(s[i]);
                    row++; i++;
                }
                row = numRows - 2;
            }
            else
            {
                while(row>=0 && i<s.size())
                {
                    ans[row].push_back(s[i]);
                    row--; i++;
                }
                row = 1;
            }
            direction = !direction ;
        }
        string final ="";
        for(auto st : ans)
        {
            final += st;
        }
    return final;
    }
};