// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
      int row = 0, i =0;
      bool direction = 1;

      vector<string>final(numRows);

        while(i<s.size())
        {
            if(direction == 1)
            {
            while(i<s.size() && row<numRows)
            {
                final[row].push_back(s[i]);
                row++ ; i++;
            }
                 row -= 2;
            }
            else
            {
            while(i<s.size() && row>=0) 
            {
                final[row].push_back(s[i]);
                row--; i++;
            }
                row = 1;
            }
            direction = !direction;
        }

        string ans ="";
        for(auto str : final)
        {
            ans += str;
        }
    return ans ;
    }
};