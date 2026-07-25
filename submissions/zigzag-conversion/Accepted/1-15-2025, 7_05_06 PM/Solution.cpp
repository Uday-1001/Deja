// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows ==1)
        {
            return s;
        }

        vector<string> zigzag(numRows);

        int row =0;
        int i =0;
        bool direction = 1;
        while(i < s.size())
        {
            if(direction > 0)
            {
                while(row < numRows && i<s.size())
                {
                    zigzag[row++].push_back(s[i++]);
                }
            row = numRows -2;
            }
            else
            {
                while(row >=0 && i<s.size())
                {
                    zigzag[row--].push_back(s[i++]);
                }
            row = 1;
            }
           
            direction = !direction;
        }   

        string ans ="";
        for(auto it : zigzag)
        {
            ans += it;
        }
    return ans;
    }
};