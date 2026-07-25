// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int row =0 , i=0;
        bool direction = 1;
        vector<string>ans(numRows);

        if(numRows == 1) return s;

        while(i<s.size())
        {
            if(direction == 1)
            {
                while(i<s.size() && row<numRows)
                {
                    ans[row].push_back(s[i]);
                    row++;
                    i++;
                }
                row -= 2;
            }
            else
            {
                while(i<s.size() && row>=0)
                {
                    ans[row].push_back(s[i]);
                    row--;
                    i++;
                }
                row = 1;
            }
            direction = !direction ;
        }
        string final = "";
    for(auto str : ans )
    {
        final += str;
    }
    return final;
    }
};